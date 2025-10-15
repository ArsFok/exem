#ifndef POINT3D_H
#define POINT3D_H

class point3d{
private:
    float x, y, z;
public:
    point3d() = default;
    point3d(float x, float y, float z);
    point3d(const point3d& p);

    point3d& operator=(const point3d& other);
    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float _x);
    void setY(float _y);
    void setZ(float _z);

    ~point3d() = default;
};

void getRoPhi(point3d& p);

#endif