#include <math.h>
namespace mt
{    
/// @brief that point of x,y
/// @tparam number thst type of number
template <typename number =float>
struct Point
{
    number x,y;
    //
    Point(number x, number y){this->x=x;this->y = y;}
};
/// @brief a line with a x,y
/// @tparam number that type of numbers
template<typename number =float>
struct vector
{
    //that Axis
    number x, y;
    /// @brief that vector between x,y
    /// @param x that x axis
    /// @param y that y axis
    vector(number x,number y){this->x = x;this->y = y;}
    /// @brief that vector in line of all points between A0 and A1 A0A1->
    /// @param A0 that begin of vector
    /// @param A1 that end vector
    vector (Point<number> A0,Point<number> A1):vector<number>(A1.x-A0.x,A1.y-A0.y){}
    //
    vector<number> operator+(vector<number> v){return vector<number>(x+v.x,y+v.y);}
    //
    vector<number> operator-(){return vector<number>(-x,-y);}
    //
    vector<number> operator-(vector<number> v){return operator+(-v);}
    //
    vector<number> operator*(number k){return vector<number>(k*x,k*y);}
};
 // namespace mt
//
/// @brief that function return  a first->.socond
/// @tparam number that type of number
/// @param first that vector
/// @param socond 
template<typename number= float>
number scalarProduct(vector<number> first,vector<number> socond){ return (first.x*socond.x)+(first.y*socond.y);}
//
template<typename number = float>
bool Aligne(vector<number> v1, vector<number> v2) {
    number cross_product = (v1.x * v2.y) - (v2.x * v1.y);
    return cross_product ==0;
}

//
template<typename number = float>
bool Aligne(Point<number> P1,Point<number> P2 ,Point<number> P3){return Aligne(vector<number>(P1,P2),vector<number>(P1,P3));}
/// @brief that return  a  ||v->|| while v-> a vector
/// @tparam number that type of numbe
/// @param __v  that vector  that calcul a ||v->||
template<typename number = float>
number abs(vector<number> __v){return sqrt(__v.x*__v.x + __v.y * __v.y);}
/// @brief that function return a Angel betwen 2 vectors
/// @tparam number that type of cordinate of vector
/// @tparam ret type angel returning
template<typename number  = float,typename ret = short>
ret Angel (vector<number> v1,vector<number> v2){return acos(scalarProduct(v1,v2)/(abs(v1)*abs(v2)));}
template <typename number = float , typename ret= short>
/// @brief that function return a Angel betwen 2 vectors
/// @tparam number that type of cordinate of vector
/// @tparam ret type angel returning
ret Angel (Point <number> P1 ,Point<number> P2 ,Point<number> P3){return Angel(vector<number>(P1,P2),vector<number>(P1,P3));}
} // namespace mt