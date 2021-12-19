#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);
	
	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat xChange, GLfloat yChange);
	glm::mat4 calculateViewMatrix();

	~Camera();

private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;	// For Frame of reference

	GLfloat yaw;	// Head moving in right and left direction
	GLfloat pitch;	// Head moving in up and down direction
	// GLfloat roll; // Not needed unless we are creating a Plane Simulation game.

	GLfloat movementSpeed;
	GLfixed turnSpeed;

	void update();	// Update these values if anything changes
};

