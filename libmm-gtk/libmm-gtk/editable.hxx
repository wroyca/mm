// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EDITABLE_H
#define _GTKMM_EDITABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkEditableInterface GtkEditableInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEditable = struct _GtkEditable;
using GtkEditableClass = struct _GtkEditableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Editable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Editable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Editable;
    using CppClassType = Editable_Class;
    using BaseObjectType = GtkEditable;
    using BaseClassType = GtkEditableInterface;

    Editable (const Editable&) = delete;
    auto
    operator= (const Editable&) -> Editable& = delete;

  private:
    friend class Editable_Class;
    static CppClassType editable_class_;

#endif
  protected:
    Editable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Editable (const Glib::Interface_Class& interface_class);

  public:
    explicit Editable (GtkEditable* castitem);

  protected:
#endif

  public:
    Editable (Editable&& src) noexcept;
    auto
    operator= (Editable&& src) noexcept -> Editable&;

    ~Editable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEditable*
    {
      return reinterpret_cast<GtkEditable*> (gobject_);
    }

    auto
    gobj () const -> const GtkEditable*
    {
      return reinterpret_cast<GtkEditable*> (gobject_);
    }

  private:
  public:
    auto
    get_text () const -> Glib::ustring;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    delete_selection () -> void;

    auto
    set_editable (bool is_editable = true) -> void;

    auto
    get_editable () const -> bool;

    auto
    insert_text (const Glib::ustring& new_text,
                 int new_text_length,
                 int& position) -> void;

    auto
    delete_text (int start_pos, int end_pos) -> void;

    auto
    get_chars (int start_pos, int end_pos) const -> Glib::ustring;

    auto
    select_region (int start_pos, int end_pos) -> void;

    auto
    get_selection_bounds (int& start_pos, int& end_pos) const -> bool;

    auto
    set_position (int position) -> void;

    auto
    get_position () const -> int;

    auto
    get_alignment () const -> float;

    auto
    set_alignment (float xalign) -> void;

    auto
    get_width_chars () const -> int;

    auto
    set_width_chars (int n_chars) -> void;

    auto
    get_max_width_chars () const -> int;

    auto
    set_max_width_chars (int n_chars) -> void;

    auto
    get_enable_undo () const -> bool;

    auto
    set_enable_undo (bool enable_undo = true) -> void;

    auto
    signal_insert_text ()
        -> Glib::SignalProxy<void (const Glib::ustring&, int*)>;

    auto
    signal_delete_text () -> Glib::SignalProxy<void (int, int)>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_cursor_position () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_enable_undo () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_undo () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selection_bound () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_editable () -> Glib::PropertyProxy<bool>;

    auto
    property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_max_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

  protected:
    virtual auto
    delete_text_vfunc (int start_pos, int end_pos) -> void;

    virtual auto
    get_text_vfunc () const -> Glib::ustring;

    virtual auto
    select_region_vfunc (int start_pos, int end_pos) -> void;

    virtual auto
    get_selection_bounds_vfunc (int& start_pos, int& end_pos) const -> bool;

  public:
  public:
  protected:
    virtual auto
    insert_text_vfunc (const Glib::ustring& text, int& position) -> void;

    virtual auto
    on_insert_text (const Glib::ustring& text, int* position) -> void;

    virtual auto
    on_delete_text (int start_pos, int end_pos) -> void;

    virtual auto
    on_changed () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Editable>;

} // namespace Glib

#endif
