
#ifndef _GDKMM_DEVICEPAD_H
#define _GDKMM_DEVICEPAD_H

#include <mm/gdk/mm-gdkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GdkDevicePadInterface GdkDevicePadInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDevicePad = struct _GdkDevicePad;
using GdkDevicePadClass = struct _GdkDevicePadClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API DevicePad_Class; } // namespace Gdk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** Pad device interface.
 *
 * %Gdk::DevicePad is an interface implemented by devices of type
 * Gdk::InputSource::TABLET_PAD. It allows querying the features provided
 * by the pad device.
 *
 * Tablet pads may contain one or more groups, each containing a subset
 * of the buttons/rings/strips available. get_n_groups()
 * can be used to obtain the number of groups, get_n_features()
 * and get_feature_group() can be combined to find out the
 * number of buttons/rings/strips the device has, and how are they grouped.
 *
 * Each of those groups have different modes, which may be used to map
 * each individual pad feature to multiple actions. Only one mode is
 * effective (current) for each given group, different groups may have
 * different current modes. The number of available modes in a group can
 * be found out through get_group_n_modes(), and the current mode for
 * a given group will be notified through the Gdk::EventPadGroupMode event.
 *
 * @newin{3,96}
 */

class GDKMM_API DevicePad : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DevicePad;
  using CppClassType = DevicePad_Class;
  using BaseObjectType = GdkDevicePad;
  using BaseClassType = GdkDevicePadInterface;

  // noncopyable
  DevicePad(const DevicePad&) = delete;
  auto operator=(const DevicePad&) -> DevicePad& = delete;

private:
  friend class DevicePad_Class;
  static CppClassType devicepad_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  DevicePad();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit DevicePad(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit DevicePad(GdkDevicePad* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DevicePad(DevicePad&& src) noexcept;
  auto operator=(DevicePad&& src) noexcept -> DevicePad&;

  ~DevicePad() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDevicePad*       { return reinterpret_cast<GdkDevicePad*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDevicePad* { return reinterpret_cast<GdkDevicePad*>(gobject_); }

private:


public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /**
   *  @var Feature BUTTON
   * A button.
   *
   *  @var Feature RING
   * A ring-shaped interactive area.
   *
   *  @var Feature STRIP
   * A straight interactive area.
   *
   *  @enum Feature
   *
   * A pad feature.
   *
   * @ingroup gdkmmEnums
   */
  enum class Feature
  {
    BUTTON,
    RING,
    STRIP
  };


  /** Returns the number of groups this pad device has.
   *
   * Pads have at least one group. A pad group is a subcollection of
   * buttons/strip/rings that is affected collectively by a same
   * current mode.
   *
   * @return The number of button/ring/strip groups in the pad.
   */
  auto get_n_groups() const -> int;

  /** Returns the number of modes that @a group may have.
   *
   * @param group_idx Group to get the number of available modes from.
   * @return The number of modes available in @a group.
   */
  auto get_group_n_modes(int group_idx) const -> int;

  /** Returns the number of features a tablet pad has.
   *
   * @param feature A pad feature.
   * @return The amount of elements of type @a feature that this pad has.
   */
  auto get_n_features(Feature feature) const -> int;

  /** Returns the group the given @a feature and @a idx belong to.
   *
   * f the feature or index do not exist in @a pad, -1 is returned.
   *
   * @param feature The feature type to get the group from.
   * @param feature_idx The index of the feature to get the group from.
   * @return The group number of the queried pad feature.
   */
  auto get_feature_group(Feature feature, int feature_idx) const -> int;

  // There are no properties, signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::DevicePad::Feature> : public Glib::Value_Enum<Gdk::DevicePad::Feature>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::DevicePad
   */
  GDKMM_API
  auto wrap(GdkDevicePad* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DevicePad>;

} // namespace Glib


#endif /* _GDKMM_DEVICEPAD_H */

