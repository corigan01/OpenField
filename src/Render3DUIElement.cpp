//
// Created by Owner on 11/4/2023.
//

#include "Render3DUIElement.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION        330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION        100
#endif

Render3DUIElement::Render3DUIElement() {
    // Initialization
    //--------------------------------------------------------------------------------------


    // VR device parameters definition
    device = {
            // Oculus Rift CV1 parameters for simulator
            .hResolution = 2160,                 // Horizontal resolution in pixels
            .vResolution = 1200,                 // Vertical resolution in pixels
            .hScreenSize = 0.133793f,            // Horizontal size in meters
            .vScreenSize = 0.0669f,              // Vertical size in meters
            .vScreenCenter = 0.04678f,           // Screen center in meters
            .eyeToScreenDistance = 0.041f,       // Distance between eye and display in meters
            .lensSeparationDistance = 0.07f,     // Lens separation distance in meters
            .interpupillaryDistance = 0.07f,     // IPD (distance between pupils) in meters

            // NOTE: CV1 uses fresnel-hybrid-asymmetric lenses with specific compute shaders
            // Following parameters are just an approximation to CV1 distortion stereo rendering
            .lensDistortionValues = { 1.0f,  0.22f, 0.24f, 0.0f} , // Lens distortion constant parameter 0
            .chromaAbCorrection = { 0.996f, -0.004f, 1.014f, 0.0f}  // Chromatic aberration correction parameter 0
    };

    // Load VR stereo config for VR device parameteres (Oculus Rift CV1 parameters)
    config = LoadVrStereoConfig(device);

    // Distortion shader (uses device lens distortion and chroma)
    distortion = LoadShader(0, TextFormat("resources/distortion%i.fs", GLSL_VERSION));

    // Update distortion shader with lens and distortion-scale parameters
    SetShaderValue(distortion, GetShaderLocation(distortion, "leftLensCenter"),
                   config.leftLensCenter, SHADER_UNIFORM_VEC2);
    SetShaderValue(distortion, GetShaderLocation(distortion, "rightLensCenter"),
                   config.rightLensCenter, SHADER_UNIFORM_VEC2);
    SetShaderValue(distortion, GetShaderLocation(distortion, "leftScreenCenter"),
                   config.leftScreenCenter, SHADER_UNIFORM_VEC2);
    SetShaderValue(distortion, GetShaderLocation(distortion, "rightScreenCenter"),
                   config.rightScreenCenter, SHADER_UNIFORM_VEC2);

    SetShaderValue(distortion, GetShaderLocation(distortion, "scale"),
                   config.scale, SHADER_UNIFORM_VEC2);
    SetShaderValue(distortion, GetShaderLocation(distortion, "scaleIn"),
                   config.scaleIn, SHADER_UNIFORM_VEC2);
    SetShaderValue(distortion, GetShaderLocation(distortion, "deviceWarpParam"),
                   device.lensDistortionValues, SHADER_UNIFORM_VEC4);
    SetShaderValue(distortion, GetShaderLocation(distortion, "chromaAbParam"),
                   device.chromaAbCorrection, SHADER_UNIFORM_VEC4);

    // Initialize framebuffer for stereo rendering
    // NOTE: Screen size should match HMD aspect ratio
    target = LoadRenderTexture(device.hResolution, device.vResolution);

    // The target's height is flipped (in the source Rectangle), due to OpenGL reasons
    sourceRec = { 0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height };
    destRec = { 0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight() };

    // Define the camera to look into our 3d world
    camera = { 0 };
    camera.position = (Vector3){ 5.0f, 2.0f, 5.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    cubePosition = { 0.0f, 0.0f, 0.0f };

    DisableCursor();                    // Limit cursor to relative movement inside the window

}


void Render3DUIElement::draw2D() {
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    BeginVrStereoMode(config);
    BeginMode3D(camera);

    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(40, 1.0f);

    EndMode3D();
    EndVrStereoMode();
    EndTextureMode();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginShaderMode(distortion);
    DrawTexturePro(target.texture, sourceRec, destRec, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
    EndShaderMode();
    DrawFPS(10, 10);
    EndDrawing();
    //----------------------------------------------------------------------------------
}