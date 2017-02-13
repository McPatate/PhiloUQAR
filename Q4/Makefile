# Copyright (C) 2017  Bastien Penavayre

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

CXX		= clang++
RM =		rm -f
SRC =		src/Semaphore.cpp
SRC_THREAD =	$(SRC) src/thread.cpp
SRC_FORK = 	$(SRC) src/fork.cpp
OBJ_THREAD =	$(SRC_THREAD:.cpp=.o)
OBJ_FORK =	$(SRC_FORK:.cpp=.o)
COMMON =       	-W -Wall -Wextra -Werror
CXXFLAGS =     	$(COMMON) -Iinc -std=c++14
LINKING =      	$(COMMON) -pthread

all:		fork thread

fork:		$(OBJ_FORK)
		$(CXX) $(OBJ_FORK) -o fork $(LINKING)

thread:		$(OBJ_THREAD)
		$(CXX) $(OBJ_THREAD) -o thread $(LINKING)

clean:
		$(RM) $(OBJ_FORK) $(OBJ_THREAD)

fclean: 	clean
		$(RM) thread fork

re: 		fclean all
