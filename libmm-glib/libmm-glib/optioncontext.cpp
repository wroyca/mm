


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/optioncontext.hpp>
#include <libmm-glib/optioncontext_p.hpp>


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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/utility.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <glib.h>

namespace Glib
{

namespace OptionContextPrivate
{
static auto
SignalProxy_translate_gtk_callback(const gchar* str, const gpointer data) -> const gchar*
{
  ustring translated_str;
  const OptionContext::SlotTranslate* the_slot =
    static_cast<OptionContext::SlotTranslate*>(data);

  try
  {
    translated_str = (*the_slot)(str);
  }
  catch (...)
  {
    exception_handlers_invoke();
  }
  return translated_str.c_str();
}

static auto SignalProxy_translate_gtk_callback_destroy (
  const gpointer data) -> void
{
  delete static_cast<OptionContext::SlotTranslate*>(data);
}

} // namespace OptionContextPrivate

OptionContext::OptionContext(const ustring & parameter_string)
: gobject_(g_option_context_new(parameter_string.c_str())), has_ownership_(true)
{
}

OptionContext::OptionContext(GOptionContext* castitem, const bool take_ownership)
: gobject_(castitem), has_ownership_(take_ownership)
{
}

OptionContext::OptionContext(OptionContext&& other) noexcept
  : gobject_(std::move(other.gobject_)),
    has_ownership_(std::move(other.has_ownership_))
{
  other.gobject_ = nullptr;
  other.has_ownership_ = false;
}

auto
OptionContext::operator=(OptionContext&& other) noexcept -> OptionContext&
{
  if (has_ownership_)
    g_option_context_free(gobj());

  gobject_ = std::move(other.gobject_);
  has_ownership_ = std::move(other.has_ownership_);

  other.gobject_ = nullptr;
  other.has_ownership_ = false;

  return *this;
}

OptionContext::~OptionContext()
{
  if (has_ownership_)
    g_option_context_free(gobj());

  gobject_ = nullptr;
}

auto OptionContext::add_group (OptionGroup &group) -> void
{
  // GObjectContext takes ownership of the GOptionGroup, unrefing it later.
  g_option_context_add_group(gobj(), group.gobj_copy());
}

auto OptionContext::set_main_group (OptionGroup &group) -> void
{
  // GObjectContext takes ownership of the GOptionGroup, unrefing it later.
  g_option_context_set_main_group(gobj(), group.gobj_copy());
}

/*
OptionGroup OptionContext::get_main_group() const
{
  const auto cobj = g_option_context_get_main_group(const_cast<GOptionContext*>( gobj()) );
  OptionGroup cppObj(const_cast<GOptionGroup*>(cobj), true); // take_copy
  return cppObj;
}

*/

auto OptionContext::set_translate_func (const SlotTranslate &slot) -> void
{
  // Create a copy of the slot. A pointer to this will be passed through the callback's data
  // parameter.
  // It will be deleted when SignalProxy_translate_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotTranslate(slot);

  g_option_context_set_translate_func(gobj(),
    &OptionContextPrivate::SignalProxy_translate_gtk_callback, slot_copy,
    &OptionContextPrivate::SignalProxy_translate_gtk_callback_destroy);
}

auto
OptionContext::get_help(
  const bool main_help) const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_option_context_get_help(
    const_cast<GOptionContext*>(gobj()), main_help, nullptr));
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::OptionError::OptionError(const Code error_code, const ustring & error_message)
: Error(G_OPTION_ERROR, error_code, error_message)
{}

Glib::OptionError::OptionError(GError* gobject)
: Error(gobject)
{}

auto Glib::OptionError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Glib::OptionError::throw_func (GError *gobject) -> void
{
  throw OptionError(gobject);
}


namespace Glib
{


auto OptionContext::set_help_enabled (
  const bool help_enabled) -> void
{
  g_option_context_set_help_enabled(gobj(), help_enabled);
}

auto OptionContext::get_help_enabled() const -> bool
{
  return g_option_context_get_help_enabled(const_cast<GOptionContext*>(gobj()));
}

auto OptionContext::set_ignore_unknown_options (
  const bool ignore_unknown) -> void
{
  g_option_context_set_ignore_unknown_options(gobj(), ignore_unknown);
}

auto OptionContext::get_ignore_unknown_options() const -> bool
{
  return g_option_context_get_ignore_unknown_options(const_cast<GOptionContext*>(gobj()));
}

auto OptionContext::set_strict_posix (
  const bool strict_posix) -> void
{
  g_option_context_set_strict_posix(gobj(), strict_posix);
}

auto OptionContext::get_strict_posix() const -> bool
{
  return g_option_context_get_strict_posix(const_cast<GOptionContext*>(gobj()));
}

auto OptionContext::parse(int& argc, char**& argv) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_option_context_parse(gobj(), &argc, &argv, &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto OptionContext::parse(char**& argv) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_option_context_parse_strv(gobj(), &argv, &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto OptionContext::get_help(
  const bool main_help, const OptionGroup& group) const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_option_context_get_help(const_cast<GOptionContext*>(gobj()), main_help, const_cast<GOptionGroup*>(group.gobj())));
}

auto OptionContext::set_summary (const ustring &summary) -> void
{
  g_option_context_set_summary(gobj(), summary.c_str());
}

auto OptionContext::get_summary() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_option_context_get_summary(const_cast<GOptionContext*>(gobj())));
}

auto OptionContext::set_description (const ustring &description) -> void
{
  g_option_context_set_description(gobj(), description.c_str());
}

auto OptionContext::get_description() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_option_context_get_description(const_cast<GOptionContext*>(gobj())));
}

auto OptionContext::set_translation_domain (const ustring &domain) -> void
{
  g_option_context_set_translation_domain(gobj(), domain.c_str());
}


} // namespace Glib


