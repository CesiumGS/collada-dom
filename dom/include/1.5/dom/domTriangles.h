#ifndef __dom150Triangles_h__
#define __dom150Triangles_h__

#include <dae/daeDocument.h>
#include <1.5/dom/domTypes.h>
#include <1.5/dom/domElements.h>

#include <1.5/dom/domInput_local_offset.h>
#include <1.5/dom/domP.h>
#include <1.5/dom/domExtra.h>

class DAE;
namespace ColladaDOM150 {

/**
 * The triangles element provides the information needed to bind vertex attributes
 * together and  then organize those vertices into individual triangles.Each
 * triangle described by the mesh has  three vertices. The first triangle
 * is formed from the first, second, and third vertices. The  second triangle
 * is formed from the fourth, fifth, and sixth vertices, and so on.
 */
class domTriangles : public daeElement
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::TRIANGLES; }
	static daeInt ID() { return 35; }
	virtual daeInt typeID() const { return ID(); }
protected:  // Attributes
/**
 *  The name attribute is the text string name of this element. Optional attribute.
 */
	xsToken attrName;
/**
 *  The count attribute indicates the number of triangle primitives. Required
 * attribute. 
 */
	domUint attrCount;
/**
 *  The material attribute declares a symbol for a material. This symbol is
 * bound to a material at  the time of instantiation. Optional attribute.
 * If the material attribute is not specified then  the lighting and shading
 * results are application defined. 
 */
	xsNCName attrMaterial;

protected:  // Elements
/**
 * The input element may occur any number of times. This input is a local
 * input with the  offset and set attributes. @see domInput
 */
	domInput_local_offset_Array elemInput_array;
/**
 * The triangles element may have zero or one p element. @see domP
 */
	domPRef elemP;
/**
 * The extra element may appear any number of times. @see domExtra
 */
	domExtra_Array elemExtra_array;

public:	//Accessors and Mutators
	/**
	 * Gets the name attribute.
	 * @return Returns a xsToken of the name attribute.
	 */
	xsToken getName() const { return attrName; }
	/**
	 * Sets the name attribute.
	 * @param atName The new value for the name attribute.
	 */
	void setName( xsToken atName ) { *(daeStringRef*)&attrName = atName;}

	/**
	 * Gets the count attribute.
	 * @return Returns a domUint of the count attribute.
	 */
	domUint getCount() const { return attrCount; }
	/**
	 * Sets the count attribute.
	 * @param atCount The new value for the count attribute.
	 */
	void setCount( domUint atCount ) { attrCount = atCount; }

	/**
	 * Gets the material attribute.
	 * @return Returns a xsNCName of the material attribute.
	 */
	xsNCName getMaterial() const { return attrMaterial; }
	/**
	 * Sets the material attribute.
	 * @param atMaterial The new value for the material attribute.
	 */
	void setMaterial( xsNCName atMaterial ) { *(daeStringRef*)&attrMaterial = atMaterial;}

	/**
	 * Gets the input element array.
	 * @return Returns a reference to the array of input elements.
	 */
	domInput_local_offset_Array &getInput_array() { return elemInput_array; }
	/**
	 * Gets the input element array.
	 * @return Returns a constant reference to the array of input elements.
	 */
	const domInput_local_offset_Array &getInput_array() const { return elemInput_array; }
	/**
	 * Gets the p element.
	 * @return a daeSmartRef to the p element.
	 */
	const domPRef getP() const { return elemP; }
	/**
	 * Gets the extra element array.
	 * @return Returns a reference to the array of extra elements.
	 */
	domExtra_Array &getExtra_array() { return elemExtra_array; }
	/**
	 * Gets the extra element array.
	 * @return Returns a constant reference to the array of extra elements.
	 */
	const domExtra_Array &getExtra_array() const { return elemExtra_array; }
protected:
	/**
	 * Constructor
	 */
	domTriangles(DAE& dae) : daeElement(dae), attrName(), attrCount(), attrMaterial(), elemInput_array(), elemP(), elemExtra_array() {}
	/**
	 * Destructor
	 */
	virtual ~domTriangles() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domTriangles &operator=( const domTriangles &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


} // ColladaDOM150
#endif
