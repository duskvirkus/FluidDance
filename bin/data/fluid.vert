#version 150

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec4 color;
in vec4 normal;
in vec2 texcoord;

out vec2 v_texcoord;

void main()
{
    v_texcoord = vec2(texcoord.x, texcoord.y);

    gl_Position = modelViewProjectionMatrix * position;
}