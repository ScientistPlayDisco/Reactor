// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 

#ifndef OO_THREADPOOL__TASK_H_
#define OO_THREADPOOL__TASK_H_
#include <functional>
namespace wd
{
  using Task = std::function<void()>;

}//end of namespace wd


#endif //OO_THREADPOOL__TASK_H_
