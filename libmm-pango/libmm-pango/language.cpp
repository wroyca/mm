


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/language.hpp>
#include <mm/pango/private/language_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

namespace Pango
{

/* PangoLanguage is just another example of inconsistent coding in atk/pango/gtk:
 * on the one hand it is defined and registered as a boxed type, on the other
 * hand it is always a pointer to some statically allocated string and thus
 * neither allocated by itself, nor copied by value, nor freed. Similar dummy
 * functions as below are defined in pango/pango-util.c but they are not exported.
 * Compare with pango/pango-util.c for reference. */
 //(I wonder who wrote this - it wasn't me. murrayc)

inline auto _pango_language_new() -> PangoLanguage*
{
  return 0;
}

inline auto _pango_language_copy(const PangoLanguage* language) -> PangoLanguage*
{
  return const_cast<PangoLanguage*>(language);
}

inline auto _pango_language_free (PangoLanguage *) -> void
{
  return;
}

Language::Language()
:
  gobject_(0)
{}

Language::Language(const Glib::ustring& language)
:
  gobject_(pango_language_from_string(language.c_str()))
{}

auto Language::get_string() const -> Glib::ustring
{
  if (gobject_)
    return pango_language_to_string(const_cast<PangoLanguage*>(gobj()));
  else
    return {};
}

auto Language::get_scripts() const -> std::vector<Script>
{
  int num_scripts = 0;
  const auto* carray = pango_language_get_scripts(const_cast<PangoLanguage*>(gobj()), &num_scripts);
  return Glib::ArrayHandler<Script>::array_to_vector((const Script*)carray, num_scripts, Glib::OWNERSHIP_NONE);
}


} /* namespace Pango */

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::Script>::value_type() -> GType
{
  return pango_script_get_type();
}


namespace Glib
{

auto wrap(PangoLanguage* object, const bool take_copy) -> Pango::Language
{
  return Pango::Language(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
auto Language::get_type() -> GType
{
  return pango_language_get_type();
}


Language::Language(const Language& other)
:
  gobject_ (other.gobject_ ? _pango_language_copy(other.gobject_) : nullptr)
{}

Language::Language(Language&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto Language::operator=(Language&& other) noexcept -> Language&
{
  Language temp (std::move(other));
  swap(temp);
  return *this;
}

Language::Language(PangoLanguage* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? _pango_language_copy(gobject) : gobject)
{}

auto Language::operator=(const Language& other) -> Language&
{
  Language temp (other);
  swap(temp);
  return *this;
}

Language::~Language() noexcept
{
  if(gobject_)
    _pango_language_free(gobject_);
}

auto Language::swap (Language &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto Language::gobj_copy() const -> PangoLanguage*
{
  return _pango_language_copy(gobject_);
}


auto Language::matches(const Glib::ustring & range_list) const -> bool
{
  return pango_language_matches(const_cast<PangoLanguage*>(gobj()), range_list.c_str());
}

auto Language::includes_script(Script script) const -> bool
{
  return pango_language_includes_script(const_cast<PangoLanguage*>(gobj()), static_cast<PangoScript>(script));
}


} // namespace Pango


