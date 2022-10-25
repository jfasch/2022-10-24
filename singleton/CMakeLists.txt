ADD_EXECUTABLE(hello hello.cpp)

# ADD_EXECUTABLE(
#   singleton-social-insurance-inflexible-main 
# 
#   singleton-social-insurance-inflexible-main.cpp
#   singleton-social-insurance-flexible-main.cpp
# 
#   social-insurance.h
#   social-insurance.cpp
# 
#   social-insurance-oegk.h
#   # social-insurance-svs.h
# )

ADD_EXECUTABLE(
  singleton-social-insurance-flexible-main 

  singleton-social-insurance-flexible-main.cpp

  social-insurance.h
  social-insurance.cpp

  social-insurance-oegk.h
  # social-insurance-svs.h
)
