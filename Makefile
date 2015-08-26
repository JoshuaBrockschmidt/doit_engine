# doit_engine - A 3D Game Engine
# Copyright (C) 2015 Joshua Brockschmidt + Robert Cochran
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2 of the GNU General Public
# License as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.

# project name
NAME = doit_engine

# build environment
CC=g++

# source files
SOURCES := $(wildcard src/*.cpp)

# object files
OBJS 	:= $(SOURCES:.cpp=.o)

# Build flags
INCLUDES    := -Iinclude
BASEFLAGS   := -O2
WARNFLAGS   := -Wall -Wextra -Wshadow -Wcast-align -Wwrite-strings -Winline
WARNFLAGS   += -Wno-attributes -Wno-deprecated-declarations
WARNFLAGS   += -Wno-div-by-zero -Wno-endif-labels -Wfloat-equal
WARNFLAGS   += -Wformat=2 -Wno-format-extra-args -Winit-self
WARNFLAGS   += -Winvalid-pch -Wmissing-format-attribute
WARNFLAGS   += -Wmissing-include-dirs -Wno-multichar -Wshadow
WARNFLAGS   += -Wno-sign-compare -Wswitch -Wsystem-headers
WARNFLAGS   += -Wno-pragmas -Wno-unused-but-set-parameter
WARNFLAGS   += -Wno-unused-but-set-variable -Wno-unused-result
WARNFLAGS   += -Wwrite-strings -Wdisabled-optimization -Wpointer-arith
WARNFLAGS   += -Werror
CPPFLAGS      := $(INCLUDES) $(BASEFLAGS)
CPPFLAGS      += -std=c++11
LDFLAGS     := -lSDL2 -lGL -lGLU -lGLEW

# build rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

warn: CPPFLAGS += $(WARNFLAGS)
warn: $(NAME)

debug: CPPFLAGS += $(WARNFLAGS) -g
debug: $(NAME)

clean:
	$(RM) $(NAME) $(OBJS)
