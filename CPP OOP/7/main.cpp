#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "Player.h"
#include "MOB.h"
#include "NPC.h"
#include "Environment.h"

int main()
{
	Point2D p1(2, 5);
	Point2D p2(3,7);
	Point2D p3(0, 9);
	Environment env;
	Player player("Player1",p1,25,100);
	NPC npc("NPC", p2);
	Mob mob1("MOB1", p3, 25, 100);
	Mob mob2("MOB2", p2, 18, 50);
	
	Entity* entities = &player;
	env.add(entities);

	entities = &npc;
	env.add(entities);

	entities = &mob1;
	env.add(entities);

	entities = &mob2;
	env.add(entities);

	Entity* e = env.getClosestAliveEntity(player, Entity::Type::MOB);

	while (e != NULL)
	{
			player.attack(*(Attacker*)e);

		e = env.getClosestAliveEntity(player, Entity::Type::MOB);
	}
	
	env.destroyEntities();

	//Point2D a(1, 1);
	//Attacker e2("sss", a);
	//a.setX(11);

	//Point2D aa(2, 1);
	//Entity e22("xxx", aa);

	//Point3D b(1, 1, 3);
	//Entity e3("ddd", b);

	//Point3D bb(1, 1, 4);
	//Entity e33("ddd", bb);

	//e33.moveTo(e3.getLocation());

	//std::cout << e3.getDistanceTo(e33) << std::endl;
	//std::cout << e3.getDistanceTo(e2) << std::endl;
	//std::cout << e22.getDistanceTo(e3) << std::endl;
	//std::cout << e3.getDistanceTo(e33) << std::endl;
	//std::cout << e33.getDistanceTo(e2) << std::endl;

	return 0;
}