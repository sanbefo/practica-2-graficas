//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"

//-------------------------------------------------------------------------

class Entity 
{
public:
	Entity() : modelMat(1.0) { }; 

	virtual ~Entity() { };

	virtual void render(glm::dmat4 const& modelViewMat) = 0;
	virtual void update();
	// modeling matrix
	glm::dmat4 const& getModelMat() const { return modelMat; };

	void setModelMat(glm::dmat4 const& aMat) { modelMat = aMat; }
  
protected:

	Mesh* mesh = nullptr;   // surface mesh
	glm::dmat4 modelMat;    // modeling matrix
	Texture textura, texturaInner;

	// transfers modelViewMat to the GPU
	virtual void uploadMvM(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity 
{
public:
	EjesRGB(GLdouble l);
	~EjesRGB();
	void render(glm::dmat4 const& modelViewMat);
};
//-------------------------------------------------------------------------
class Poliespiral : public Entity
{
public:
	Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	~Poliespiral();
	void render(glm::dmat4 const& modelViewMat);
};
//-------------------------------------------------------------------------
class Dragon : public Entity
{
public:
	Dragon(GLuint numVert);
	~Dragon();
	void render(glm::dmat4 const& modelViewMat);
};
//-------------------------------------------------------------------------
class Triangulo : public Entity
{
public:
	Triangulo(GLdouble r);
	~Triangulo();
	void render(glm::dmat4 const& modelViewMat);
	void update();
	GLdouble anguloRota = 0;
	GLdouble anguloTraslada = 0;
};

class Rectangulo : public Entity
{
public:
	Rectangulo(GLdouble w, GLdouble h);
	~Rectangulo();
	void render(glm::dmat4 const& modelViewMat);
};

class Suelo : public Entity
{
public:
	Suelo(GLdouble w, GLdouble h);
	Suelo(GLdouble w, GLdouble h, GLuint rw, GLuint rh);
	~Suelo();
	void render(glm::dmat4 const& modelViewMat);
};

class Estrella3D : public Entity
{
public:
	Estrella3D(GLdouble re, GLdouble np, GLdouble h);
	~Estrella3D();
	void render(glm::dmat4 const& modelViewMat);
	void update();
	GLdouble anguloRota = 0;
	GLdouble anguloTraslada = 0;
};

class Caja : public Entity
{
public:
	Caja(GLdouble l);
	~Caja();
	void render(glm::dmat4 const& modelViewMat);
};

class Canjilon : public Caja
{
public:
	Canjilon(GLdouble l);
	~Canjilon();
	void render(glm::dmat4 const& modelViewMat);
	void update();
	GLdouble anguloRota = 0;
	GLdouble anguloTraslada = 0;
};

class Tablero : public Caja
{
public:
	Tablero(GLdouble l);
	~Tablero();
	void update();
	GLdouble anguloRota = 0;
	GLdouble anguloTraslada = 0;
};

class QuadricEntity : public Entity
{
public:
	QuadricEntity();
	~QuadricEntity() { gluDeleteQuadric(q); };
protected:
	GLUquadricObj* q;
};

class Sphere : public QuadricEntity
{
public:
	Sphere(GLdouble r); // r is the radius of the sphere
	void render(glm::dmat4 const& modelViewMat);
protected:
	GLdouble r;
};

class Cylinder : public QuadricEntity
{
public:
	Cylinder(GLdouble br, GLdouble tr, GLdouble h);
	void render(glm::dmat4 const& modelViewMat);
protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble height;
};

class Disk : public QuadricEntity
{
public:
	Disk(GLdouble ir, GLdouble o);
	void render(glm::dmat4 const& modelViewMat);
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
};

class PartialDisk : public QuadricEntity
{
public:
	PartialDisk(GLdouble ir, GLdouble o, GLdouble sa, GLdouble sw);
	void render(glm::dmat4 const& modelViewMat);
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
	GLdouble startAngle;
	GLdouble sweepAngle;
};

class Rotor : public QuadricEntity
{
public:
	Rotor(GLdouble br, GLdouble tr, GLdouble h);
	~Rotor();
	void render(glm::dmat4 const& modelViewMat);
	void update();
	GLdouble anguloRota = 0;
	GLdouble anguloTraslada = 0;
protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble height;

};
#endif //_H_Entities_H_