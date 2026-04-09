#ifndef point3d_h
#define point3d_h

class point3d
{
private:
    float x, y, z;
public:
    point3d()=default;
    point3d(float x, float y, float z);
    point3d(const point3d& p);
    
    point3d& operator=(const point3d& other);
    ~point3d()=default;

    float getx() const;
    float gety() const;
    float getz() const;
    void setx(float _x);
    void sety(float _y);
    void setz(float _z);
};

const point3d getRoPhi(const point3d& other);

#endif