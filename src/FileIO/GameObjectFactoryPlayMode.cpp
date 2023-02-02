#include "GameObjectFactoryPlayMode.h"
#include <iostream>
#include "TransformComponent.h"
#include "StandardGraphicsComponent.h"
#include "AnimatedGraphicsComponent.h"
#include "PlayerUpdateComponent.h"
#include "RectColliderComponent.h"
#include "InvaderUpdateComponent.h"
#include "BulletUpdateComponent.h"
#include "MothershipUpdateComponent.h"

void GameObjectFactoryPlayMode::buildGameObject(
	GameObjectBlueprint& bp,
	std::vector<GameObject>& gameObjects)
{
	float row_qty = bp.getRowQuantity();
	// set the initial location
	float locationX = bp.getLocationX();

	// Wrap i tall up in a do while loop.
	do {
		GameObject gameObject;
		gameObject.setTag(bp.getName());

		auto it = bp.getComponentList().begin();
		auto end = bp.getComponentList().end();
		for (it;
			it != end;
			++it)
		{
			if (*it == "Transform")
			{
				gameObject.addComponent(make_shared<TransformComponent>(
					bp.getWidth(),
					bp.getHeight(),
					// Ensure we use the calculated value not the locaiton stored in the blueprint
					Vector2f(locationX, bp.getLocationY())));
			}
			else if (*it == "Player Update")
			{
				gameObject.addComponent(make_shared
					<PlayerUpdateComponent>());
			}
			else if (*it == "Invader Update")
			{
				gameObject.addComponent(make_shared
					<InvaderUpdateComponent>());
			}
			else if (*it == "Bullet Update")
			{
				gameObject.addComponent(make_shared
					<BulletUpdateComponent>());
			}
			else if (*it == "Mothership Update")
			{
				gameObject.addComponent(make_shared<MothershipUpdateComponent>());
			}
			else if (*it == "Standard Graphics")
			{
				shared_ptr<StandardGraphicsComponent> sgp =
					make_shared<StandardGraphicsComponent>();

				gameObject.addComponent(sgp);
				sgp->initialiseGraphics(
					bp.getBitmapName(),
					Vector2f(bp.getWidth(),
						bp.getHeight()));
			}
			else if (*it == "Animated Graphics")
			{
				shared_ptr<AnimatedGraphicsComponent> agp =
					make_shared<AnimatedGraphicsComponent>();

				gameObject.addComponent(agp);
				agp->initialiseGraphics(
					bp.getBitmapName(),
					Vector2f(bp.getWidth(),
						bp.getHeight()));
			}
		}

		if (bp.getEncompassingRectCollider()) {
			shared_ptr<RectColliderComponent> rcc =
				make_shared<RectColliderComponent>(
					bp.getEncompassingRectColliderLabel());

			gameObject.addComponent(rcc);
			// Use calculated value
			rcc->setOrMoveCollider(locationX,
				bp.getLocationY(),
				bp.getWidth(),
				bp.getHeight());
		}

		gameObjects.push_back(gameObject);
		// Calculate the next starting location based on gap and object width.
		locationX += bp.getGapX() + bp.getWidth();

		// Decrement the counter so we don't get stuck in an eternal loop.
		row_qty--;
	} while (row_qty > 0);
}

