/**
 * PLAIN SERVER Engine ( https://github.com/viticm/plainserver )
 * $Id system.h
 * @link https://github.com/viticm/plianserver for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2014/07/11 10:36
 * @uses engine system class
 */
#ifndef ENGINE_SYSTEM_H_
#define ENGINE_SYSTEM_H_

#include "engine/config.h"
#include "common/base/singleton.h"
#include "common/engine/kernel.h"

namespace engine {

class System : public ps_common_engine::Kernel, 
  public ps_common_base::Singleton<System> {

 public:
   System();
   ~System();

 public:
   static System *getsingleton_pointer();
   static System &getsingleton(); 

 public:
   bool init();

 public:
   ps_common_db::Manager *get_dbmanager();

 private:
   bool init_setting();

};

}; //namespace engine

#define ENGINE_SYSTEM_POINTER engine::System::getsingleton_pointer()

extern engine::System *g_engine_system;

#endif //ENGINE_SYSTEM_H_
