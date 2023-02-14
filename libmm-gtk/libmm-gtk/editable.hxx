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
  class GTKMM_API Editable_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Editable : public Glib::Interface
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

    static void
    add_interface (GType gtype_implementer);

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

    void
    set_text (const Glib::ustring& text);

    void
    delete_selection ();

    void
    set_editable (bool is_editable = true);

    auto
    get_editable () const -> bool;

    void
    insert_text (const Glib::ustring& new_text,
                 int new_text_length,
                 int& position);

    void
    delete_text (int start_pos, int end_pos);

    auto
    get_chars (int start_pos, int end_pos) const -> Glib::ustring;

    void
    select_region (int start_pos, int end_pos);

    auto
    get_selection_bounds (int& start_pos, int& end_pos) const -> bool;

    void
    set_position (int position);

    auto
    get_position () const -> int;

    auto
    get_alignment () const -> float;

    void
    set_alignment (float xalign);

    auto
    get_width_chars () const -> int;

    void
    set_width_chars (int n_chars);

    auto
    get_max_width_chars () const -> int;

    void
    set_max_width_chars (int n_chars);

    auto
    get_enable_undo () const -> bool;

    void
    set_enable_undo (bool enable_undo = true);

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
    virtual void
    delete_text_vfunc (int start_pos, int end_pos);

    virtual auto
    get_text_vfunc () const -> Glib::ustring;

    virtual void
    select_region_vfunc (int start_pos, int end_pos);

    virtual auto
    get_selection_bounds_vfunc (int& start_pos, int& end_pos) const -> bool;

  public:
  public:
  protected:
    virtual void
    insert_text_vfunc (const Glib::ustring& text, int& position);

    virtual void
    on_insert_text (const Glib::ustring& text, int* position);

    virtual void
    on_delete_text (int start_pos, int end_pos);

    virtual void
    on_changed ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Editable>;

} // namespace Glib

#endif
