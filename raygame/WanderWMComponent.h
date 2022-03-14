#include "Actor.h"
#include <time.h>
#include "Component.h"
#include "Transform2D.h"
#include "MoveComponent.h"

class WanderComponent : public Component {
public:
	WanderComponent() {};
	~WanderComponent() {};
	
	void start() override;
	void update(float deltaTime) override;

	int getRadius() { return m_radius; };
	void setRadius(int value) { m_radius = value; };

	int getDistance() { return m_distance; };
	void setDistance(int value) { m_distance = value; };

private:
	int m_distance;
	int m_radius;
	
	MathLibrary::Vector2 m_randomVector;
	MathLibrary::Vector2 m_velocity;
	
	
};

void WanderComponent::start() {
	srand(time(NULL));
	setDistance(5);
	setRadius(10);
}

void WanderComponent::update(float deltaTime) {
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();

	//Owers Velocity normalized 
	 m_velocity = getOwner()->getComponent<MoveComponent>()->getVelocity().getNormalized();

	 float randX = rand() % 10;
	 float randY = rand() % 10;

	 m_randomVector = {(float)cos(randX), (float)sin(randY) };

	//The posistion of the circle 
	MathLibrary::Vector2 circleOffset = ownerPosition + m_velocity * getDistance();

	MathLibrary::Vector2 circlePosition = circleOffset + ownerPosition;

}