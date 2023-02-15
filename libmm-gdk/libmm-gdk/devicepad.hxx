// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DEVICEPAD_H
#define _GDKMM_DEVICEPAD_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkDevicePadInterface GdkDevicePadInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDevicePad = struct _GdkDevicePad;
using GdkDevicePadClass = struct _GdkDevicePadClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API DevicePad_Class;
}
#endif

namespace Gdk
{

  class GDKMM_API DevicePad : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DevicePad;
    using CppClassType = DevicePad_Class;
    using BaseObjectType = GdkDevicePad;
    using BaseClassType = GdkDevicePadInterface;

    DevicePad (const DevicePad&) = delete;
    auto
    operator= (const DevicePad&) -> DevicePad& = delete;

  private:
    friend class DevicePad_Class;
    static CppClassType devicepad_class_;

#endif
  protected:
    DevicePad ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit DevicePad (const Glib::Interface_Class& interface_class);

  public:
    explicit DevicePad (GdkDevicePad* castitem);

  protected:
#endif

  public:
    DevicePad (DevicePad&& src) noexcept;
    auto
    operator= (DevicePad&& src) noexcept -> DevicePad&;

    ~DevicePad () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDevicePad*
    {
      return reinterpret_cast<GdkDevicePad*> (gobject_);
    }

    auto
    gobj () const -> const GdkDevicePad*
    {
      return reinterpret_cast<GdkDevicePad*> (gobject_);
    }

  private:
  public:
    enum class Feature
    {
      BUTTON,
      RING,
      STRIP
    };

    auto
    get_n_groups () const -> int;

    auto
    get_group_n_modes (int group_idx) const -> int;

    auto
    get_n_features (Feature feature) const -> int;

    auto
    get_feature_group (Feature feature, int feature_idx) const -> int;

  public:
  public:
  protected:
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::DevicePad::Feature>
    : public Glib::Value_Enum<Gdk::DevicePad::Feature>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  GDKMM_API auto
  wrap (GdkDevicePad* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DevicePad>;

} // namespace Glib

#endif
