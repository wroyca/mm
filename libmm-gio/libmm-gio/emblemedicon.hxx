
#ifndef _GIOMM_EMBLEMEDICON_H
#define _GIOMM_EMBLEMEDICON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/object.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/emblem.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GEmblemedIcon = struct _GEmblemedIcon;
using GEmblemedIconClass = struct _GEmblemedIconClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API EmblemedIcon_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Icons with Emblems
 *
 * EmblemedIcon is an implementation of Icon that supports adding an emblem to
 * an icon. Adding multiple emblems to an icon is ensured via add_emblem().
 *
 * Note that EmblemedIcon allows no control over the position of the emblems.
 * See also Emblem for more information.
 *
 * @newin{2,20}
 */

class GIOMM_API EmblemedIcon
: public Glib::Object,
  public Icon
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EmblemedIcon;
  using CppClassType = EmblemedIcon_Class;
  using BaseObjectType = GEmblemedIcon;
  using BaseClassType = GEmblemedIconClass;

  // noncopyable
  EmblemedIcon(const EmblemedIcon&) = delete;
  auto operator=(const EmblemedIcon&) -> EmblemedIcon& = delete;

private:  friend class EmblemedIcon_Class;
  static CppClassType emblemedicon_class_;

protected:
  explicit EmblemedIcon(const Glib::ConstructParams& construct_params);
  explicit EmblemedIcon(GEmblemedIcon* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EmblemedIcon(EmblemedIcon&& src) noexcept;
  auto operator=(EmblemedIcon&& src) noexcept -> EmblemedIcon&;

  ~EmblemedIcon() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GEmblemedIcon*       { return reinterpret_cast<GEmblemedIcon*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GEmblemedIcon* { return reinterpret_cast<GEmblemedIcon*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GEmblemedIcon*;

private:


protected:
  //We have this constructor because g_emblemed_icon_new() may take a nullptr emblem parameter.
  /** Creates a new emblemed icon for @a icon with no emblem.
   * @param icon An Icon.
   *
   * @newin{2,28}
   */
  explicit EmblemedIcon(const Glib::RefPtr<Icon>& icon);

  /** Creates a new emblemed icon for @a icon with the emblem @a emblem.
   * @param icon An Icon.
   * @param emblem An Emblem.
   */
   explicit EmblemedIcon(const Glib::RefPtr<Icon>& icon, const Glib::RefPtr<Emblem>& emblem);


public:

  /** Creates a new emblemed icon for @a icon with the emblem @a emblem.
   * @param icon An Icon.
   * @param emblem An Emblem.
   * @result An Icon.
   */

  static auto create(const Glib::RefPtr<Icon>& icon, const Glib::RefPtr<Emblem>& emblem) -> Glib::RefPtr<EmblemedIcon>;


  /** Creates a new emblemed icon for @a icon with no emblem.
   * @param icon An Icon.
   * @result An Icon.
   *
   * @newin{2,28}
   */

  static auto create(const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<EmblemedIcon>;


  /** Gets the main icon for @a emblemed.
   *
   * @newin{2,18}
   *
   * @return A Icon that is owned by @a emblemed.
   */
  auto get_icon() -> Glib::RefPtr<Icon>;

  /** Gets the main icon for @a emblemed.
   *
   * @newin{2,18}
   *
   * @return A Icon that is owned by @a emblemed.
   */
  auto get_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the list of emblems for the @a icon.
   *
   * @newin{2,18}
   *
   * @return A List of
   * Emblems that is owned by @a emblemed.
   */
  auto get_emblems() -> std::vector<Glib::RefPtr<Emblem>>;


  /** Gets the list of emblems for the @a icon.
   *
   * @newin{2,18}
   *
   * @return A List of
   * Emblems that is owned by @a emblemed.
   */
  auto get_emblems() const -> std::vector<Glib::RefPtr<const Emblem>>;


  /** Adds @a emblem to the List of Emblems.
   *
   * @newin{2,18}
   *
   * @param emblem A Emblem.
   */
  void add_emblem(const Glib::RefPtr<Emblem>& emblem);

  /** Removes all the emblems from @a icon.
   *
   * @newin{2,28}
   */
  void clear_emblems();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::EmblemedIcon
   */
  GIOMM_API
  auto wrap(GEmblemedIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::EmblemedIcon>;
}


#endif /* _GIOMM_EMBLEMEDICON_H */

