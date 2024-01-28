cc_library(
    name = "boilerplate",
    srcs = [
        "boilerplate.h"
    ],
)

cc_test(
  name = "boilerplate_test",
  size = "small",
  srcs = ["boilerplate_test.cc"],
  deps = ["@com_google_googletest//:gtest_main", ":boilerplate"],
  linkstatic=True
)