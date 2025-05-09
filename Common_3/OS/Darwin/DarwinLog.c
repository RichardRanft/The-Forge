/*
 * Copyright (c) 2017-2025 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "../../Application/Config.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "../Interfaces/IOperatingSystem.h"

// interfaces
#include "../../Utilities/Interfaces/ILog.h"

#include "../../Utilities/Interfaces/IMemory.h"

static bool gIsInteractiveMode = true;

void _EnableInteractiveMode(bool isInteractiveMode) { gIsInteractiveMode = isInteractiveMode; }

bool _IsInteractiveMode(void) { return gIsInteractiveMode; }

void _OutputDebugStringV(const char* str, va_list args)
{
#if defined(FORGE_DEBUG)
    vprintf(str, args);
#endif
}

void _OutputDebugString(const char* str, ...)
{
#if defined(FORGE_DEBUG)
    va_list arglist;
    va_start(arglist, str);
    vprintf(str, arglist);
    va_end(arglist);
#endif
}

void _FailedAssertImpl(const char* file, int line, const char* statement, const char* message)
{
    if (gIsInteractiveMode)
    {
        __builtin_debugtrap();
    }
}

void _PrintUnicode(const char* str, bool error) { printf("%s", str); }
