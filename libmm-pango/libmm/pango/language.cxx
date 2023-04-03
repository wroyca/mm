// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/language.hxx>
#include <libmm/pango/language_p.hxx>

namespace Pango
{

  inline auto
  _pango_language_new () -> PangoLanguage*
  {
    return 0;
  }

  inline auto
  _pango_language_copy (const PangoLanguage* language) -> PangoLanguage*
  {
    return const_cast<PangoLanguage*> (language);
  }

  inline auto
  _pango_language_free (PangoLanguage*) -> void
  {
    return;
  }

  Language::Language ()
    : gobject_ (0)
  {
  }

  Language::Language (const Glib::ustring& language)
    : gobject_ (pango_language_from_string (language.c_str ()))
  {
  }

  auto
  Language::get_string () const -> Glib::ustring
  {
    if (gobject_)
      return pango_language_to_string (const_cast<PangoLanguage*> (gobj ()));
    else
      return {};
  }

  auto
  Language::get_scripts () const -> std::vector<Script>
  {
    int num_scripts = 0;
    const auto* carray = pango_language_get_scripts (
        const_cast<PangoLanguage*> (gobj ()),
        &num_scripts);
    return Glib::ArrayHandler<Script>::array_to_vector ((const Script*) carray,
                                                        num_scripts,
                                                        Glib::OWNERSHIP_NONE);
  }

} // namespace Pango

namespace
{
}

auto
Glib::Value<Pango::Script>::value_type () -> GType
{
  return pango_script_get_type ();
}

namespace Glib
{

  auto
  wrap (PangoLanguage* object, const bool take_copy) -> Pango::Language
  {
    return Pango::Language (object, take_copy);
  }

} // namespace Glib

namespace Pango
{

  auto
  Language::get_type () -> GType
  {
    return pango_language_get_type ();
  }

  Language::Language (const Language& other)
    : gobject_ (other.gobject_ ? _pango_language_copy (other.gobject_) :
                                 nullptr)
  {
  }

  Language::Language (Language&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  Language::operator= (Language&& other) noexcept -> Language&
  {
    Language temp (std::move (other));
    swap (temp);
    return *this;
  }

  Language::Language (PangoLanguage* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? _pango_language_copy (gobject) :
                                         gobject)
  {
  }

  auto
  Language::operator= (const Language& other) -> Language&
  {
    Language temp (other);
    swap (temp);
    return *this;
  }

  Language::~Language () noexcept
  {
    if (gobject_)
      _pango_language_free (gobject_);
  }

  auto
  Language::swap (Language& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  Language::gobj_copy () const -> PangoLanguage*
  {
    return _pango_language_copy (gobject_);
  }

  auto
  Language::matches (const Glib::ustring& range_list) const -> bool
  {
    return pango_language_matches (const_cast<PangoLanguage*> (gobj ()),
                                   range_list.c_str ());
  }

  auto
  Language::includes_script (Script script) const -> bool
  {
    return pango_language_includes_script (const_cast<PangoLanguage*> (gobj ()),
                                           static_cast<PangoScript> (script));
  }

} // namespace Pango
