/*Open LEFA Proj
2023*/

#include"Transform.h";


GTransform
transform_init(GVector3 position, Quaternion rotation)
{
	GTransform self;

	self.position = position;
	self.rotation = rotation;
	return self;
}

GTransform
transform_identity()
{
	GTransform self;

	self.position = vector3_init(0.0f, 0.0f, 0.0f);
	self.rotation = quaternion_init(0.0f, 0.0f, 0.0f, 1.0f);
	return self;
}

GTransform
transform_look(GVector3 position, GVector3 direction, GVector3 up)
{
	GTransform self;

	self.rotation = quaternion_look (direction, up);
	self.position = quaternion_transform(self.rotation, vector3_invert (position));
	return self;
}

GTransform
transform_lookat(GVector3 position, GVector3 center, GVector3 up)
{
	GTransform self;
	GVector3 direction;

	direction = vector3_subtract(position, center);
	direction = vector3_normalize(position);
	self.rotation = quaternion_look(direction, up);
	self.position = quaternion_transform(self.rotation, vector3_invert (position));
	return self;
}

GTransform
transform_invert(GTransform self)
{
	GVector3 tmp;
	GTransform result;

	tmp = vector3_invert(self.position);
	result.rotation = quaternion_conjugate(self.rotation);
	result.position = quaternion_transform(result.rotation, tmp);
	return result;
}

GTransform
transform_conjugate(GTransform self)
{
	GTransform result;

	result.position = self.position;
	result.rotation = quaternion_conjugate (self.rotation);
	return result;
}

GTransform
transform_multiply(GTransform self,
                   GTransform transform)
{
	GTransform result;

	result.position = quaternion_transform(self.rotation, transform.position);
	result.position = vector3_add(self.position, result.position);
	result.rotation = quaternion_multiply(self.rotation, transform.rotation);
	return result;
}

GTransform
transform_relative(GTransform self,
                   GTransform transform)
{
	Quaternion inverse;
	Quaternion rotation;
	GVector3 position;

	inverse  = quaternion_conjugate(self.rotation);
	position = vector3_subtract(transform.position, self.position);
	position = quaternion_transform(inverse, position);
	rotation = quaternion_multiply(inverse, transform.rotation);
	return transform_init(position, rotation);
}

GVector3
transform_transform(GTransform self,
                    GVector3  vector)
{
	GVector3 result;

	result = quaternion_transform(self.rotation, vector);
	result = vector3_add(result, self.position);
	return result;
}

GTransform
transform_snap(GTransform self,
               GTransform child)
{
	GTransform result;
	GTransform inverse;

	inverse = transform_invert(child);
	result = transform_multiply(self, inverse);
	return result;
}

GMatrix4
transform_get_modelview(GTransform self)
{
	GVector3 pos;
	GVector3 dir;
	GVector3 up;

	pos = self.position;
	dir = quaternion_get_basis(self.rotation, 2);
	dir = vector3_multiply(dir, -1.0f);
	up  = quaternion_get_basis(self.rotation, 1);
	return matrix4_look (pos.x, pos.y, pos.z, dir.x, dir.y, dir.z, up.x, up.y, up.z);
}