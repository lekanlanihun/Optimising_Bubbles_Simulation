cmake_minimum_required(VERSION 2.8)

SET ( EXECUTABLE myprogram )

# UNCOMMENT FOR GRAPHICS
#FIND_PACKAGE( Qt COMPONENTS QtOpenGL REQUIRED )
#SET( QT_USE_QTOPENGL TRUE )


FILE ( GLOB SOURCES ./*.cpp ./program_files/*.cpp ./*.cpp ./Quad_Tree/*.cpp)   
FILE ( GLOB HEADERS ./*.h ./program_files/*.h ./*.h ./Quad_Tree/*.h)




#INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} /usr/include/ /usr/local/include/ /usr/local/qwt-6.1.1-svn/include/ ${CMAKE_CURRENT_BINARY_DIR} ./EXP/RENDERING /usr/local/include/opencv2/ )
# UNCOMMENT FOR GRAPHICS

ADD_EXECUTABLE( ${EXECUTABLE} ${SOURCES})

# UNCOMMENT FOR GRAPHICS
TARGET_LINK_LIBRARIES( ${EXECUTABLE} ${OpenCV_LIBS} ${OPENGL_glu_LIBRARY}  ${GLUT_LIBRARIES} -lGL -lGLU  ${QT_LIBRARIES} )#revel xvidcore
#TARGET_LINK_LIBRARIES( ${EXECUTABLE} "-L/sw/lib -lgsl -lgslcblas -lm -L/usr/local/qwt-6.1.1-svn/lib" )
# UNCOMMENT FOR GRAPHICS
