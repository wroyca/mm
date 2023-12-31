// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COMBOBOXTEXT_H
#define _GTKMM_COMBOBOXTEXT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/combobox.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBoxText = struct _GtkComboBoxText;
using GtkComboBoxTextClass = struct _GtkComboBoxTextClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ComboBoxText_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ComboBoxText : public ComboBox
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
    friend LIBMM_GTK_SYMEXPORT class ComboBoxText_Class;
    static CppClassType comboboxtext_class_;

  protected:
    explicit ComboBoxText (const glib::ConstructParams& construct_params);
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

    auto
    append (const glib::ustring& text) -> void;

    auto
    append (const glib::ustring& id, const glib::ustring& text) -> void;

    auto
    insert (int position, const glib::ustring& text) -> void;

    auto
    insert (int position, const glib::ustring& id, const glib::ustring& text)
        -> void;

    auto
    prepend (const glib::ustring& text) -> void;

    auto
    prepend (const glib::ustring& id, const glib::ustring& text) -> void;

    auto
    remove_text (int position) -> void;

    auto
    get_active_text () const -> glib::ustring;

    auto
    remove_all () -> void;

    auto
    set_active_text (const glib::ustring& text) -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkComboBoxText* object, bool take_copy = false) -> gtk::ComboBoxText*;
} // namespace glib

#endif

#endif
