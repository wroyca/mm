// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_REQUISITION_H
#define _GTKMM_REQUISITION_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-glib/value.hxx>

namespace Gtk
{

  class GTKMM_API Requisition
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Requisition;
    using BaseObjectType = GtkRequisition;
#endif

    Requisition (const Requisition& other) noexcept;
    auto
    operator= (const Requisition& other) noexcept -> Requisition&;

    Requisition (Requisition&& other) noexcept;
    auto
    operator= (Requisition&& other) noexcept -> Requisition&;

    static auto
    get_type () -> GType G_GNUC_CONST;

    Requisition ();

    explicit Requisition (const GtkRequisition* gobject);

    auto
    gobj () -> GtkRequisition*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GtkRequisition*
    {
      return &gobject_;
    }

  protected:
    GtkRequisition gobject_;

  private:
  public:
    Requisition (int width, int height);

    auto
    get_width () const -> int;
    auto
    set_width (const int& value) -> void;
    auto
    get_height () const -> int;
    auto
    set_height (const int& value) -> void;
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkRequisition* object) -> Gtk::Requisition&;

  GTKMM_API auto
  wrap (const GtkRequisition* object) -> const Gtk::Requisition&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GTKMM_API Value<Gtk::Requisition>
    : public Glib::Value_Boxed<Gtk::Requisition>
  {
  };
#endif

} // namespace Glib

#endif
