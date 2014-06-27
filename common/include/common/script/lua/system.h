/**
 * PLAIN SERVER Engine ( https://github.com/viticm/plainserver )
 * $Id system.h
 * @link https://github.com/viticm/plianserver for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2014/06/26 16:48
 * @uses script lua module system class(script interface)
 */
#ifndef PS_COMMON_SCRIPT_LUA_SYSTEM_H_
#define PS_COMMON_SCRIPT_LUA_SYSTEM_H_

#include "common/script/lua/config.h"
#include "common/base/singleton.h"
#include "common/base/hashmap/template.h"
#include "common/script/lua/vm.h"
#include "common/script/lua/stack.h"

namespace ps_common_script {

namespace lua {

class System : public ps_common_base::Singleton<System> {

 public:
   System();
   ~System();

 public:
   static System *getsingleton_pointer();
   static System &getsingleton();

 public:
   static bool lua_reloadscript_always_;
   static bool lua_recordscript_step_;
   static const char *kLuaScriptStepFileName;
   static const int32_t kLuaScriptCountMax;

 public:
   void init();
   void release();
   void register_function();
   bool find_function(lua_State *L, const char *name);
   bool verify_function(lua_State *L, const char **names);
   void enter_runstep(int16_t sceneid, 
                      int32_t scriptid, 
                      const char* function_name);
   void leave_runstep(int16_t sceneid, 
                      int32_t scriptid, 
                      const char* function_name);
   bool reloadscript(int16_t sceneid, int32_t scriptid);
   bool reloadscript(int32_t scriptid);
   void *getscript_byid(int32_t scriptid);
   bool addscript(int32_t scriptid, void *data);

 public:
   bool lua_scriptload(const char *luascript);

 public:
   static bool check_paramnumber(lua_State *L, int32_t count);
   static bool is_paramnumber(lua_State *L, 
                              int32_t index, 
                              const char *function_name);
   static bool is_paramstring(lua_State *L,
                              int32_t index,
                              const char *function_name);
   static int32_t getscript_stepid(lua_State *L);
   static void mark_scriptname(lua_State *L, const char* scriptname);
   static void check_scriptvalid(void *file, 
                                 int32_t scriptid, 
                                 const char *function_name);
   static void dumpstack();

 public:
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              int64_t param3);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              int64_t param3,
                              int64_t param4);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              int64_t param3,
                              int64_t param4,
                              int64_t param5);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              int64_t param3,
                              int64_t param4,
                              int64_t param5,
                              int64_t param6);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              int64_t param3,
                              int64_t param4,
                              int64_t param5,
                              int64_t param6,
                              int64_t param7);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              float param3,
                              float param4);
   int64_t run_scriptfunction(int16_t sceneid, 
                              int32_t scriptid, 
                              const char *function_name,
                              int64_t param0,
                              int64_t param1,
                              int64_t param2,
                              const char *param3,
                              const char *param4);
 public:
   const char *get_rootpath();

 protected:
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            int64_t param3);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            int64_t param3,
                            int64_t param4);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            int64_t param3,
                            int64_t param4,
                            int64_t param5);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            int64_t param3,
                            int64_t param4,
                            int64_t param5,
                            int64_t param6);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            int64_t param3,
                            int64_t param4,
                            int64_t param5,
                            int64_t param6,
                            int64_t param7);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            int64_t param2,
                            float param3);
   int64_t run_filefunction(const char *filename, 
                            int32_t scriptid, 
                            const char *function_name,
                            int64_t param0,
                            int64_t param1,
                            const char *param2,
                            const char *param3);

 private:
   VM VM_;
   ps_common_base::hashmap::Template<int32_t, void *> script_loaded_;

};
  
int32_t call_scriptfunction(lua_State *L);

};

}; //namespace ps_common_script

#define SCRIPT_LUASYSTEM_POINTER \
ps_common_script::lua::System::getsingleton_pointer()

#endif //PS_COMMON_SCRIPT_LUA_SYSTEM_H_