// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGOBJECT_H
#define _GTKMM_STRINGOBJECT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StringObject_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StringObject : public glib::Object
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
    explicit StringObject (const glib::ConstructParams& construct_params);
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
    create (const glib::ustring& string) -> glib::RefPtr<StringObject>;

    auto
    get_string () const -> glib::ustring;

    auto
    property_string () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStringObject* object, bool take_copy = false) -> glib::RefPtr<gtk::StringObject>;
} // namespace glib

#endif
