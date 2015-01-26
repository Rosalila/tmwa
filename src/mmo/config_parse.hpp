#pragma once
//    config_parse.hpp - Framework for per-server config parsers.
//
//    Copyright © 2014 Ben Longbons <b.r.longbons@gmail.com>
//
//    This file is part of The Mana World (Athena server)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "fwd.hpp"


namespace tmwa
{
using ConfigItemParser = bool(io::Spanned<XString> key, io::Spanned<ZString> value);

bool is_comment(XString line);
bool config_split(io::Spanned<ZString> line, io::Spanned<XString> *key, io::Spanned<ZString> *value);

/// Master config parser. This handles 'import' and 'version-ge' etc.
/// Then it defers to the inferior parser for a line it does not understand.
bool load_config_file(ZString filename, ConfigItemParser slave);
} // namespace tmwa
