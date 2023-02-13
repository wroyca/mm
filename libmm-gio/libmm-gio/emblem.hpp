
#ifndef _GIOMM_EMBLEM_H
#define _GIOMM_EMBLEM_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/icon.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GEmblem = struct _GEmblem;
using GEmblemClass = struct _GEmblemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Emblem_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** An object for emblems
 *
 * Emblem is an implementation of GIcon that supports having an emblem, which
 * is an icon with additional properties. It can than be added to a
 * EmblemedIcon.
 *
 * Currently, only metainformation about the emblem's origin is supported. More
 * may be added in the future.
 *
 * @newin{2,20}
 */

class GIOMM_API Emblem
: public Glib::Object,
  public Icon
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Emblem;
  using CppClassType = Emblem_Class;
  using BaseObjectType = GEmblem;
  using BaseClassType = GEmblemClass;

  // noncopyable
  Emblem(const Emblem&) = delete;
  auto operator=(const Emblem&) -> Emblem& = delete;

private:  friend class Emblem_Class;
  static CppClassType emblem_class_;

protected:
  explicit Emblem(const Glib::ConstructParams& construct_params);
  explicit Emblem(GEmblem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Emblem(Emblem&& src) noexcept;
  auto operator=(Emblem&& src) noexcept -> Emblem&;

  ~Emblem() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GEmblem*       { return reinterpret_cast<GEmblem*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GEmblem* { return reinterpret_cast<GEmblem*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GEmblem*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Origin UNKNOWN
   * Emblem of unknown origin.
   *
   *  @var Origin DEVICE
   * Emblem adds device-specific information.
   *
   *  @var Origin LIVEMETADATA
   * Emblem depicts live metadata, such as "readonly".
   *
   *  @var Origin TAG
   * Emblem comes from a user-defined tag, e.g. set by nautilus (in the future).
   *
   *  @enum Origin
   *
   * GEmblemOrigin is used to add information about the origin of the emblem
   * to Emblem.
   *
   * @newin{2,18}
   *
   * @ingroup giommEnums
   */
  enum class Origin
  {
    UNKNOWN,
    DEVICE,
    LIVEMETADATA,
    TAG
  };


protected:
  /** Creates a new emblem for @a icon.
   * @param icon A Gio::Icon containing the icon.
   */
   explicit Emblem(const Glib::RefPtr<Icon>& icon);


  /** Creates a new emblem for @a icon.
   * @param icon A Gio::Icon containing the icon.
   * @param origin An Origin value defining the emblem's origin
   */
   explicit Emblem(const Glib::RefPtr<Icon>& icon, Origin origin);


public:
  /** Creates a new emblem for @a icon.
   * @param icon A Gio::Icon containing the icon.
   */

  static auto create(const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<Emblem>;


  /** Creates a new emblem for @a icon.
   * @param icon A Gio::Icon containing the icon.
   * @param origin An Origin value defining the emblem's origin
   */

  static auto create(const Glib::RefPtr<Icon>& icon, Origin origin) -> Glib::RefPtr<Emblem>;


  /** Gives back the icon from @a emblem.
   *
   * @newin{2,18}
   *
   * @return A Icon. The returned object belongs to
   * the emblem and should not be modified or freed.
   */
  auto get_icon() -> Glib::RefPtr<Icon>;

  /** Gives back the icon from @a emblem.
   *
   * @newin{2,18}
   *
   * @return A Icon. The returned object belongs to
   * the emblem and should not be modified or freed.
   */
  auto get_icon() const -> Glib::RefPtr<const Icon>;

  /** Gets the origin of the emblem.
   *
   * @newin{2,18}
   *
   * @return The origin of the emblem.
   */
  auto get_origin() const -> Origin;


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
   * @relates Gio::Emblem
   */
  GIOMM_API
  auto wrap(GEmblem* object, bool take_copy = false) -> Glib::RefPtr<Gio::Emblem>;
}


#endif /* _GIOMM_EMBLEM_H */

