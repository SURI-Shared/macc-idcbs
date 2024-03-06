#include "common.h"

int GRID_COLS = 8;

namespace std
{
std::ostream& operator<<(std::ostream& os, const Constraint& constraint)
{
    const auto& [loc1, loc2, timestep, positive_constraint] = constraint;
    if (loc2 == -1)
        os << "<(" << loc1 / GRID_COLS << "," << loc1 % GRID_COLS << "), " << timestep;
    else
        os << "<(" << loc1 / GRID_COLS << "," << loc1 % GRID_COLS << "), (" << loc2 / GRID_COLS << ","
           << loc2 % GRID_COLS << "), " << timestep;
    if (positive_constraint)
        os << ", positive>";
    else
        os << ", negative>";
    return os;
}
}

namespace std
{
std::ostream& operator<<(std::ostream& os, const Conflict& conflict)
{
    const auto& [agent1, agent2, loc1, loc2, timestep] = conflict;
    if (loc2 == -1)
        os << "<" << agent1 << ", " << agent2 << ", (" << loc1 / GRID_COLS << "," << loc1 % GRID_COLS << "), "
           << timestep << ">";
    else
        os << "<" << agent1 << ", " << agent2 << ", (" << loc1 / GRID_COLS << "," << loc1 % GRID_COLS << "), ("
           << loc2 / GRID_COLS << "," << loc2 % GRID_COLS << "), " << timestep << ">";
    return os;
}
}

auto fmt::formatter<Constraint>::format(Constraint constraint, format_context &ctx) const ->decltype(ctx.out())
{
    std::ostringstream msg;
    msg<<constraint;
    return fmt::formatter<std::string>::format(msg.str(),ctx);
}

auto fmt::formatter<Conflict>::format(Conflict conflict, format_context &ctx) const ->decltype(ctx.out())
    {
        std::ostringstream msg;
        msg<<conflict;
        return fmt::formatter<std::string>::format(msg.str(),ctx);
    }