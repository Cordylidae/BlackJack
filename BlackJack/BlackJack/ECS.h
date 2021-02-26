#ifndef ECS_H
#define ECS_H

#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include<bitset>
#include<array>

class Component;
class Entity;
class Manager;

using ComponentID = int;
using Group = int;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr int maxComponents = 64;
constexpr int maxGroups = 64;// constexpr - possible to evaluate the value of the function or variable at compile time

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;



	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};

class Entity
{
private:
	Manager& manager;
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitSet groupBitSet;

public:
	Entity(Manager& mManager) : manager(mManager) {}

	void update()
	{
		for (auto& comp : components) comp->update();
	}
	void draw() 
	{
		for (auto& comp : components) comp->draw();
	}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	bool hasGroup(Group group)
	{
		return groupBitSet[group];
	}

	void addGroup(Group group);
	void delGroup(Group group)
	{
		groupBitSet[group];
	}

	template<typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>];
	}

	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* comp(new T(std::forward<TArgs>(mArgs)...)); 
		comp->entity = this;
		std::unique_ptr<Component> uPtr{ comp };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = comp;
		componentBitSet[getComponentTypeID<T>()] = true;

		comp->init();
		return *comp;
	}

	template <typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*> (ptr);

	}
	
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;
public:
	void update()
	{
		for (auto& ent : entities) ent->update();
	}
	void draw()
	{
		for (auto& ent : entities) ent->draw();
	}
	void draw(std::vector<Entity*> ents)
	{
		for (auto& ent : ents) ent->draw();
	}

	void refresh()
	{

		for (Group i=0; i < maxGroups; i++)
		{
			auto& v(groupedEntities[i]);
			v.erase(std::remove_if(std::begin(v), std::end(v),
					[i](Entity* mEntity)
			{
				return !mEntity->isActive() || !mEntity->hasGroup(i);
			}),
					std::end(v));
			
		}

		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
		{
			return !mEntity->isActive();
		}),
			std::end(entities));
	}

	void AddToGroup(Entity* entity, Group group)
	{
		groupedEntities[group].emplace_back(entity);
	}

	std::vector<Entity*>& getGroup(Group group)
	{
		return groupedEntities[group];
	}


	Entity& addEntity()
	{
		Entity* ent = new Entity(*this);
		std::unique_ptr<Entity> uPtr{ ent };
		entities.emplace_back(std::move(uPtr));

		return *ent;
	}

	~Manager() {}
};

#endif // !ECS_H