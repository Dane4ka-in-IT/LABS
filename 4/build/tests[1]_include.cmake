if(EXISTS "/mnt/c/Users/ITdiakon/Documents/Desktop/AA/danich/4/build/tests[1]_tests.cmake")
  include("/mnt/c/Users/ITdiakon/Documents/Desktop/AA/danich/4/build/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()
