#include"LocationHandler.hpp"
namespace adas
{
LocationHandler::LocationHandler(const Location& location) noexcept 
    : position(location.x, location.y), 
    direction(&Direction::GetDirection(location.heading))
{
}
void LocationHandler::Move(void)noexcept
{
   position += direction->Move();
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
}