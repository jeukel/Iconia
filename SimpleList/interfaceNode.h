#ifndef NODE_H
#define NODE_H
#include "cstddef"
template < class K >
/*!
 * \brief The Node class is the base of all other
 * data structure nodes. The idea is to keep relationship
 * between all the different nodes.
 */
class interfaceNode {
public:
    interfaceNode();
    //Node(K pElement);
    virtual ~interfaceNode();
    virtual K* getElement();
    virtual void setElement(K pElement);
protected:
    K _element;
};

/*!
 * Template::Interface Setup.
 */
template <typename K>
interfaceNode<K>::interfaceNode()
{
    this->_element =0;
}

/*!
 * interfaceNode Destructor.
 */
template <typename K>
interfaceNode<K>::~interfaceNode(){}

/*!
 * Set element.
 */
template <typename K>
void interfaceNode<K>::setElement(K pElement)
{
    this->_element = pElement;
}

/*!
 * Get Element.
 */
template <typename K>
K* interfaceNode<K>::getElement()
{
    return &(this->_element);
}

#endif // NODE_H
