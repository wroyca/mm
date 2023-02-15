// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGOBJECT_H
#define _GTKMM_STRINGOBJECT_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API StringObject_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API StringObject : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StringObject;
    using CppClassType = StringObject_Class;
    using BaseObjectType = GtkStringObject;
    using BaseClassType = GtkStringObjectClass;

    StringObject (const StringObject&) = delete;
    auto
    operator= (const StringObject&) -> StringObject& = delete;

  private:
    friend class StringObject_Class;
    static CppClassType stringobject_class_;

  protected:
    explicit StringObject (const Glib::ConstructParams& construct_params);
    explicit StringObject (GtkStringObject* castitem);

#endif

  public:
    StringObject (StringObject&& src) noexcept;
    auto
    operator= (StringObject&& src) noexcept -> StringObject&;

    ~StringObject () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStringObject*
    {
      return reinterpret_cast<GtkStringObject*> (gobject_);
    }

    auto
    gobj () const -> const GtkStringObject*
    {
      return reinterpret_cast<GtkStringObject*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStringObject*;

  private:
  public:
    static auto
    create (const Glib::ustring& string) -> Glib::RefPtr<StringObject>;

    auto
    get_string () const -> Glib::ustring;

    auto
    property_string () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkStringObject* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringObject>;
} // namespace Glib

#endif
