/**************************************************************************/
/*  test_font_variation.h                                                           */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_FONT_VARIATION_H
#define TEST_FONT_VARIATION_H

#include "scene/resources/font.h" // Where the code we are testing is located
#include "tests/test_macros.h" // These two provide the necessary testing framework
#include "tests/test_utils.h"

namespace TestFontVariation {

TEST_CASE("[FontVariation] Default Base Font") { // No base font assigned
    Ref<FontVariation> font; 
    Ref<Font> f;
    font.instantiate();
    f.instantiate();
    f = font->_get_base_font_or_default(); // Base Font was never assigned, so default is loaded.
    CHECK(f == font->theme_font); // [Theme] is the default font declared in font.h 
}

TEST_CASE("[FontVariation] Embolden") { // Tests the getter and setter functions for variation emboldening.
    Ref<FontVariation> font; 
    font.instantiate();
    font->set_variation_embolden(10.2);
    float embolden = font->get_variation_embolden();
    CHECK(embolden == 10.2);
}

TEST_CASE("[FontVariation] Face Index") { // Tests the getter and setter functions for face index.
    Ref<FontVariation> font; 
    font.instantiate();
    font->set_variation_face_index(4);
    int face_index_variable = font->get_variation_face_index();
    CHECK(face_index_variable == 4);
}

TEST_CASE("[FontVariation] Baseline Offset") { // Tests the getter and setter functions for baseline offset.
    Ref<FontVariation> font; 
    font.instantiate();
    font->set_baseline_offset(3.1);
    float baseline_offset_variable = font->get_baseline_offset();
    CHECK(baseline_offset_variable == 3.1);
}

} // namespace TestFontVariation

#endif // TEST_FONT_VARIATION_H

/****
 * Notes (Written by Me for the Purposes of this Assignment):
 * 
 * Required for Compiling:
 * - MingGW or Visual Studio Community
 * - Python
 *      - Scons Framework
 * 
 * Files needed to understand the code:
 * ..\godot\scene\resources\font.h  (This is the source code we are testing, specifically the FontVariation section)
 * ..\godot\doc\classes\FontVariation.xml (This is the documentation for the code we are testing. Explains each function)
 * 
 * https://docs.godotengine.org/en/latest/contributing/development/compiling/ (Compile Instructions)
 * https://docs.godotengine.org/en/latest/contributing/development/compiling/compiling_for_windows.html (Compile Instructions For Windows)
 * 
 * Guide for Unit Tests (uses DocTest, which is similar to Catch)
 * https://docs.godotengine.org/en/latest/contributing/development/core_and_modules/unit_testing.html 
 * 
 * 
 * Console Command Process
 * scons tests=yes / python -mSCons tests=yes
 * scons devTools=yes / python -mSCons devTools=yes (Optional, will take the longest)
 * --test --source-file="*test_font_variation*" --success
 * 
*/