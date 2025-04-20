#pragma once
/** \file
*/

/** \brief Captura de forma segura en un n&uacute;mero
* \tparam Tipo de n&uacute;mero a capturar
*
* \param n N&uacute;mero a capturar.
* \param solicitud Mensaje de solicitud del n&uacute;mero a capturar.
* \return Nada.
*
*/
template <typename Tipo>
void CapturaSegura(Tipo& n, const char solicitud[]);
#include "CapturaSegura.tpp"

