// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COMBOBOXTEXT_H
#define _GTKMM_COMBOBOXTEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/combobox.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBoxText = struct _GtkComboBoxText;
using GtkComboBoxTextClass = struct _GtkComboBoxTextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ComboBoxText_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ComboBoxText : public ComboBox
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ComboBoxText CppObjectType;
    typedef ComboBoxText_Class CppClassType;
    typedef GtkComboBoxText BaseObjectType;
    typedef GtkComboBoxTextClass BaseClassType;
#endif

    ComboBoxText (ComboBoxText&& src) noexcept;
    auto
    operator= (ComboBoxText&& src) noexcept -> ComboBoxText&;

    ComboBoxText (const ComboBoxText&) = delete;
    auto
    operator= (const ComboBoxText&) -> ComboBoxText& = delete;

    ~ComboBoxText () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ComboBoxText_Class;
    static CppClassType comboboxtext_class_;

  protected:
    explicit ComboBoxText (const Glib::ConstructParams& construct_params);
    explicit ComboBoxText (GtkComboBoxText* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkComboBoxText*
    {
      return reinterpret_cast<GtkComboBoxText*> (gobject_);
    }

    auto
    gobj () const -> const GtkComboBoxText*
    {
      return reinterpret_cast<GtkComboBoxText*> (gobject_);
    }

  private:
  public:
    explicit ComboBoxText (bool has_entry = false);

    void
    append (const Glib::ustring& text);

    void
    append (const Glib::ustring& id, const Glib::ustring& text);

    void
    insert (int position, const Glib::ustring& text);

    void
    insert (int position, const Glib::ustring& id, const Glib::ustring& text);

    void
    prepend (const Glib::ustring& text);

    void
    prepend (const Glib::ustring& id, const Glib::ustring& text);

    void
    remove_text (int position);

    auto
    get_active_text () const -> Glib::ustring;

    void
    remove_all ();

    void
    set_active_text (const Glib::ustring& text);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkComboBoxText* object, bool take_copy = false) -> Gtk::ComboBoxText*;
} // namespace Glib

#endif
