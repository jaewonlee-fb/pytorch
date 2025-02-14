#include <torch/csrc/python_headers.h>
#ifdef _MSC_VER
#include <c10/util/win32-headers.h>
#endif
#include <structmember.h>

#define THP_HOST_HALF

#include <TH/TH.h>
// See Note [TH abstraction violation]
//  - Used to get at the allocator associated with a storage
#include <TH/THStorageFunctions.hpp>
#include <libshm.h>
#include <torch/csrc/THP.h>
#include <torch/csrc/copy_utils.h>
#include <torch/csrc/DynamicTypes.h>
#include <torch/csrc/CudaIPCTypes.h>
#include <torch/csrc/Device.h>
#include <torch/csrc/autograd/utils/wrap_outputs.h>

#include <fmt/format.h>

// NOLINTNEXTLINE(bugprone-suspicious-include)
#include <torch/csrc/generic/Storage.cpp>
#include <TH/THGenerateByteType.h>

template<>
void THPPointer<THStorage>::free() {
  if (ptr) {
    THStorage_free(ptr);
  }
}
