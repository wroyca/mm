/* Copyright (C) 2011 The glibmm Development Team
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

#include <libmm-glib/vectorutils.hpp>

namespace Glib
{

namespace Container_Helpers
{

auto
create_bool_array(std::vector<bool>::const_iterator pbegin, const std::size_t size) -> gboolean*
{
  gboolean* const array(static_cast<gboolean*>(g_malloc((size + 1) * sizeof(gboolean))));
  gboolean* const array_end(array + size);

  for (gboolean* pdest(array); pdest != array_end; ++pdest)
  {
    *pdest = *pbegin;
    ++pbegin;
  }

  *array_end = false;
  return array;
}

} // namespace Container_Helpers

/**** Glib::ArrayHandler<bool> ************************/

auto
ArrayHandler<bool, Container_Helpers::TypeTraits<bool>>::array_to_vector(
  const CType* array, std::size_t array_size, const OwnershipType ownership) -> VectorType
{
  if (array)
  {
    // it will handle destroying data depending on passed ownership.
    ArrayKeeperType keeper(array, array_size, ownership);
#ifdef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS
    return VectorType(ArrayIteratorType(array), ArrayIteratorType(array + array_size));
#else
    VectorType temp;
    temp.reserve(array_size);
    Glib::Container_Helpers::fill_container(
      temp, ArrayIteratorType(array), ArrayIteratorType(array + array_size));
    return temp;
#endif
  }
  return {};
}

auto
ArrayHandler<bool, Container_Helpers::TypeTraits<bool>>::array_to_vector(
  const CType* array, const OwnershipType ownership) -> VectorType
{
  return array_to_vector(array, Container_Helpers::compute_array_size2(array), ownership);
}

auto
ArrayHandler<bool, Container_Helpers::TypeTraits<bool>>::vector_to_array(
  const VectorType& vector) -> ArrayKeeperType
{
  return ArrayKeeperType(
    Container_Helpers::create_bool_array(vector.begin(), vector.size()),
    vector.size(), OWNERSHIP_SHALLOW);
}

} // namespace Glib
