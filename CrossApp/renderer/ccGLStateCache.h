
#ifndef __CCGLSTATE_H__
#define __CCGLSTATE_H__

#include <cstdint>

#include "CCGL.h"
#include "platform/CCPlatformMacros.h"

NS_CC_BEGIN

/**
 * @addtogroup renderer
 * @{
 */

class GLProgram;
class Texture2D;
namespace GL {

/** Vertex attrib flags. */
enum {
    VERTEX_ATTRIB_FLAG_NONE       = 0,

    VERTEX_ATTRIB_FLAG_POSITION   = 1 << 0,
    VERTEX_ATTRIB_FLAG_COLOR      = 1 << 1,
    VERTEX_ATTRIB_FLAG_TEX_COORD = 1 << 2,
    VERTEX_ATTRIB_FLAG_NORMAL = 1 << 3,
    VERTEX_ATTRIB_FLAG_BLEND_WEIGHT = 1 << 4,
    VERTEX_ATTRIB_FLAG_BLEND_INDEX = 1 << 5,
    
    VERTEX_ATTRIB_FLAG_POS_COLOR_TEX = (VERTEX_ATTRIB_FLAG_POSITION | VERTEX_ATTRIB_FLAG_COLOR | VERTEX_ATTRIB_FLAG_TEX_COORD),
};

/** 
 * Invalidates the GL state cache.
 *
 * If CC_ENABLE_GL_STATE_CACHE it will reset the GL state cache.
 * @since v2.0.0
 */
void CC_DLL invalidateStateCache(void);

/** 
 * Uses the GL program in case program is different than the current one.

 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will the glUseProgram() directly.
 * @since v2.0.0
 */
void CC_DLL useProgram(GLuint program);

/** 
 * Deletes the GL program. If it is the one that is being used, it invalidates it.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will the glDeleteProgram() directly.
 * @since v2.0.0
 */
void CC_DLL deleteProgram(GLuint program);

/** 
 * Uses a blending function in case it not already used.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will the glBlendFunc() directly.
 * @since v2.0.0
 */
void CC_DLL blendFunc(GLenum sfactor, GLenum dfactor);

/** 
 * Resets the blending mode back to the cached state in case you used glBlendFuncSeparate() or glBlendEquation().
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will just set the default blending mode using GL_FUNC_ADD.
 * @since v2.0.0
 */
void CC_DLL blendResetToCache(void);

/** 
 * Sets the projection matrix as dirty.
 * @since v2.0.0
 */
void CC_DLL setProjectionMatrixDirty(void);

/** 
 * Will enable the vertex attribs that are passed as flags.
 * Possible flags:
 * 
 *    * VERTEX_ATTRIB_FLAG_POSITION
 *    * VERTEX_ATTRIB_FLAG_COLOR
 *    * VERTEX_ATTRIB_FLAG_TEX_COORDS
 * 
 * These flags can be ORed. The flags that are not present, will be disabled.
 * 
 * @since v2.0.0
 */
void CC_DLL enableVertexAttribs(uint32_t flags);

/** 
 * If the texture is not already bound to texture unit 0, it binds it.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glBindTexture() directly.
 * @since v2.0.0
 */
void CC_DLL bindTexture2D(GLuint textureId);

/** 
 * If the texture is not already bound to a given unit, it binds it.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glBindTexture() directly.
 * @since v2.1.0
 */
void CC_DLL bindTexture2DN(GLuint textureUnit, GLuint textureId);

/** If the texture is not already bound to a given unit, it binds it.
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glBindTexture() directly.
 * @since v3.6
 */
void CC_DLL bindTextureN(GLuint textureUnit, GLuint textureId, GLuint textureType = GL_TEXTURE_2D);

/** 
 * It will delete a given texture. If the texture was bound, it will invalidate the cached.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glDeleteTextures() directly.
 * @since v2.0.0
 */
void CC_DLL deleteTexture(GLuint textureId);

/** 
 * Select active texture unit.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glActiveTexture() directly.
 * @since v3.0
 */
void CC_DLL activeTexture(GLenum texture);

/** 
 * If the vertex array is not already bound, it binds it.
 *
 * If CC_ENABLE_GL_STATE_CACHE is disabled, it will call glBindVertexArray() directly.
 * @since v2.0.0
 */
void CC_DLL bindVAO(GLuint vaoId);

// end of support group
/// @}

} // Namespace GL
NS_CC_END
    

#endif /* __CCGLSTATE_H__ */