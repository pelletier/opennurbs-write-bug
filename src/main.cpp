#include <opennurbs/opennurbs_public.h>
#include <iostream>
#include <memoryapi.h>
#include <winnt.h>

int main(int argc, char** argv) {
  MEMORY_BASIC_INFORMATION meminfo;
  SIZE_T ret = VirtualQuery(&ON_StackedText::Empty, &meminfo, sizeof(meminfo));

  if (ret == 0) {
    std::cerr << "Could not retrieve memory page protection info" << std::endl;
  } else {
    bool worked = VirtualProtect(meminfo.AllocationBase,
                                 (char *)(&ON_StackedText::Empty) -
                                     (char *)meminfo.AllocationBase,
                                 PAGE_EXECUTE_READWRITE, &meminfo.Protect);
    if (!worked) {
      std::cerr << "Failed to change memory page protection" << std::endl;
    }
  }

  ON::Begin();
  ON::End();

  return EXIT_SUCCESS;
}
