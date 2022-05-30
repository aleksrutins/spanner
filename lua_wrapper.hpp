#pragma once
#include <lua.hpp>
#include <string>

void run_script(lua_State *L, std::string script);
void run_file(lua_State *L, std::string filename);