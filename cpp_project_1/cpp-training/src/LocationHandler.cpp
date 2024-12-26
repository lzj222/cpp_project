#include"LocationHandler.hpp"
namespace adas
{
LocationHandler::LocationHandler(const Location& location,VehicleType type) noexcept 
    : position(location.x, location.y), 
    direction(&Direction::GetDirection(location.heading)),
    vehicleType(type)
{
}
void LocationHandler::Move(void)noexcept
{
   position += direction->Move();
}
void LocationHandler::BackMove(void)noexcept
{
    position -= direction->Move();
}
void LocationHandler::TurnLeft(void)noexcept
{
    direction = &(direction->DirectionLeft());
}
void LocationHandler::TurnRight(void)noexcept
{
    direction = &(direction->DirectionRight());
}
Location LocationHandler::GetInfo(void) const noexcept
{
    return Location{position.GetX(), position.GetY(), direction->GetHeading()};
}

void LocationHandler::FastChange(void)noexcept
{
    isFastMove=!isFastMove;
}
bool LocationHandler::IsFastMove(void)const noexcept
{
    return isFastMove;
}
void LocationHandler::Reverse(void)noexcept//改变倒车状态
{
    isReverse=!isReverse;
}
bool LocationHandler::IsReverse(void)const noexcept//判断是否处在倒车状态
{
    return isReverse;
}
VehicleType LocationHandler::GetVehicleType(void)const noexcept
{
    return vehicleType;
}
}