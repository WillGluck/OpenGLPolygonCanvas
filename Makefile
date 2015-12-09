LIBS := -lGL -lGLU -lglut
INCLUDES := -I ./include/
CPP_FILES := $(wildcard ./src/*.cpp)

OpenGLPolygonsCanvas:
	gcc -v -o OpenGLPolygonCanvas $(CPP_FILES) $(LIBS) $(INCLUDES)
