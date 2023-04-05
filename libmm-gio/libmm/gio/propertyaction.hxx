// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROPERTYACTION_H
#define _GIOMM_PROPERTYACTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/action.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPropertyAction = struct _GPropertyAction;
using GPropertyActionClass = struct _GPropertyActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT PropertyAction_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT PropertyAction : public glib::Object,
                                   public Action
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PropertyAction;
    using CppClassType = PropertyAction_Class;
    using BaseObjectType = GPropertyAction;
    using BaseClassType = GPropertyActionClass;

    PropertyAction (const PropertyAction&) = delete;
    auto
    operator= (const PropertyAction&) -> PropertyAction& = delete;

  private:
    friend class PropertyAction_Class;
    static CppClassType propertyaction_class_;

  protected:
    explicit PropertyAction (const glib::ConstructParams& construct_params);
    explicit PropertyAction (GPropertyAction* castitem);

#endif

  public:
    PropertyAction (PropertyAction&& src) noexcept;
    auto
    operator= (PropertyAction&& src) noexcept -> PropertyAction&;

    ~PropertyAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GPropertyAction*
    {
      return reinterpret_cast<GPropertyAction*> (gobject_);
    }

    auto
    gobj () const -> const GPropertyAction*
    {
      return reinterpret_cast<GPropertyAction*> (gobject_);
    }

    auto
    gobj_copy () -> GPropertyAction*;

  private:
  protected:
    PropertyAction (const glib::ustring& name,
                    const glib::PropertyProxy_Base& property_proxy,
                    bool invert_boolean = false);

  public:
    static auto
    create (const glib::ustring& name,
            const glib::PropertyProxy_Base& property_proxy,
            bool invert_boolean = false) -> glib::RefPtr<PropertyAction>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_parameter_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

    auto
    property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_state_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

    auto
    property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>;

    auto
    property_invert_boolean () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GPropertyAction* object, bool take_copy = false) -> glib::RefPtr<gio::PropertyAction>;
} // namespace glib

#endif
