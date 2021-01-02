#if 0

//listing of all techniques and passes with embedded asm listings 

technique basic_noLight
{
    pass P0
    {
        vertexshader = 
            asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   float4x4 matWorldViewProj;
            //
            //
            // Registers:
            //
            //   Name             Reg   Size
            //   ---------------- ----- ----
            //   matWorldViewProj c0       4
            //
            
                vs_3_0
                dcl_position v0
                dcl_texcoord v1
                dcl_position o0
                dcl_texcoord o1.xy
                dp4 o0.x, v0, c0
                dp4 o0.y, v0, c1
                dp4 o0.z, v0, c2
                dp4 o0.w, v0, c3
                mov o1.xy, v1
            
            // approximately 5 instruction slots used
            };

        pixelshader = 
            asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   float4 alphaTestValueAB_filterMode_addBlend;
            //   float4 amount__blend_modulate_vs_add__hdrTexture01;
            //   float flasherMode;
            //
            //
            // Registers:
            //
            //   Name                                        Reg   Size
            //   ------------------------------------------- ----- ----
            //   alphaTestValueAB_filterMode_addBlend        c0       1
            //   amount__blend_modulate_vs_add__hdrTexture01 c1       1
            //   flasherMode                                 c2       1
            //
            
                preshader
                add r0.x, c2.x, (-1)
                neg r1.x, r0.x
                max r2.x, r0.x, r1.x
                neg r0.x, r2.x
                cmp ob1.x, r0.x, (1), (0)
                neg r0.x, c1.z
                max r1.x, r0.x, c1.z
                neg r0.x, r1.x
                add r0.y, c2.x, (-2)
                cmp r1.x, r0.y, (0), (1)
                cmp ob2.x, r0.x, r1.x, (0)
                mov ob0.x, r1.x
                neg r0.x, c2.x
                max c5.x, r0.x, c2.x
                neg r0.x, c1.w
                max r1.x, r0.x, c1.w
                neg r0.x, r1.x
                cmp ob3.x, r0.x, (1), (0)
                add r0.x, c0.z, (-2)
                neg r1.x, r0.x
                max r2.x, r0.x, r1.x
                neg r0.x, r2.x
                cmp ob4.x, r0.x, (1), (0)
                add r0.x, c0.z, (-3)
                neg r1.x, r0.x
                max c10.x, r0.x, r1.x
                add r0.x, c0.z, (-1)
                neg r1.x, r0.x
                max c11.x, r0.x, r1.x
                add r0.x, c0.z, (-4)
                neg r1.x, r0.x
                max c12.x, r0.x, r1.x
                neg r0.x, c0.w
                max c13.x, r0.x, c0.w
                rcp r0.x, c1.y
                add c14.x, r0.x, (-1)
            
            // approximately 36 instructions used
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   float4 alphaTestValueAB_filterMode_addBlend;
            //   float4 amount__blend_modulate_vs_add__hdrTexture01;
            //   float4 staticColor_Alpha;
            //   sampler2D texSampler0;
            //   sampler2D texSampler1;
            //
            //
            // Registers:
            //
            //   Name                                        Reg   Size
            //   ------------------------------------------- ----- ----
            //   staticColor_Alpha                           c15      1
            //   alphaTestValueAB_filterMode_addBlend        c16      1
            //   amount__blend_modulate_vs_add__hdrTexture01 c17      1
            //   texSampler0                                 s0       1
            //   texSampler1                                 s1       1
            //
            
                ps_3_0
                def c18, 1, 0, -1, 0.0404499993
                def c19, 0.0773993805, 0.947867274, 0.0521326996, 2.4000001
                def c20, -0.5, 0, 0, 0
                dcl_texcoord v0.xy
                dcl_2d s0
                dcl_2d s1
                if b0
                  texld r0, v0, s0
                  add r1.x, -r0.w, c16.x
                  cmp r1.x, r1.x, c18.x, c18.y
                else
                  mov r0, c18.y
                  mov r1.x, c18.y
                endif
                if b1
                  texld r2, v0, s1
                  add r1.y, -r2.w, c16.y
                  cmp r1.y, r1.y, c18.x, c18.y
                  add r1.y, r1.y, r1.x
                  cmp r1.x, -r1.y, c18.y, c18.x
                else
                  mov r2, c18.y
                endif
                cmp r1, -r1.x, c18.x, c18.z
                texkill r1
                if b2
                  add r1.xyz, -r0, c18.w
                  mul r3.xy, r0, c19.x
                  mad r3.zw, r0.xyxy, c19.y, c19.z
                  pow r1.w, r3.z, c19.w
                  cmp r0.x, r1.x, r3.x, r1.w
                  pow r1.x, r3.w, c19.w
                  cmp r0.y, r1.y, r3.y, r1.x
                  mul r1.x, r0.z, c19.x
                  mad r1.y, r0.z, c19.y, c19.z
                  pow r3.x, r1.y, c19.w
                  cmp r0.z, r1.z, r1.x, r3.x
                endif
                mul r1, r0, c15
                mov r3, c15
                cmp r1, -c5.x, r1, r3
                if b1
                  if b3
                    add r3.xyz, -r2, c18.w
                    mul r4.xy, r2, c19.x
                    mad r4.zw, r2.xyxy, c19.y, c19.z
                    pow r3.w, r4.z, c19.w
                    cmp r2.x, r3.x, r4.x, r3.w
                    pow r3.x, r4.w, c19.w
                    cmp r2.y, r3.y, r4.y, r3.x
                    mul r3.x, r2.z, c19.x
                    mad r3.y, r2.z, c19.y, c19.z
                    pow r4.x, r3.y, c19.w
                    cmp r2.z, r3.z, r3.x, r4.x
                  endif
                  if b4
                    add r3, r0, c20.x
                    mul r4, r0, r2
                    add r4, r4, r4
                    add r5, -r0, c18.x
                    add r5, r5, r5
                    add r6, -r2, c18.x
                    mad r5, r5, -r6, c18.x
                    cmp r3, r3, r5, r4
                    max r4, r3, c18.y
                    mul r1, r1, r4
                  endif
                  mul r3, r0, r2
                  mul r3, r3, c17.x
                  mul r3, r1, r3
                  cmp r3, -c10.x, r3, r1
                  mad r4, r2, c17.x, r0
                  mul r4, r3, r4
                  cmp r3, -c11.x, r4, r3
                  add r0, -r0, c18.x
                  add r2, -r2, c18.x
                  mad r0, r0, -r2, c18.x
                  max r2, r0, c18.y
                  mul r0, r2, r3
                  cmp r1, -c12.x, r0, r3
                endif
                mul r0.x, r1.w, -c17.y
                mul r0.xyz, r0.x, r1
                cmp oC0.xyz, -c13.x, r1, r0
                mov r0.x, c13.x
                cmp oC0.w, -r0.x, r1.w, c14.x
            
            // approximately 104 instruction slots used (2 texture, 102 arithmetic)
            };
    }
}

#endif

const BYTE g_flasherShaderCode[] =
{
      1,   9, 255, 254,   0,   4, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  96,   0,   0,   0, 
    120,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,   0, 
    109,  97, 116,  87, 111, 114, 
    108, 100,  86, 105, 101, 119, 
     80, 114, 111, 106,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     87,  79,  82,  76,  68,  86, 
     73,  69,  87,  80,  82,  79, 
     74,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
    184,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     18,   0,   0,   0, 115, 116, 
     97, 116, 105,  99,  67, 111, 
    108, 111, 114,  95,  65, 108, 
    112, 104,  97,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0, 252,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  37,   0,   0,   0, 
     97, 108, 112, 104,  97,  84, 
    101, 115, 116,  86,  97, 108, 
    117, 101,  65,  66,  95, 102, 
    105, 108, 116, 101, 114,  77, 
    111, 100, 101,  95,  97, 100, 
    100,  66, 108, 101, 110, 100, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     84,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     44,   0,   0,   0,  97, 109, 
    111, 117, 110, 116,  95,  95, 
     98, 108, 101, 110, 100,  95, 
    109, 111, 100, 117, 108,  97, 
    116, 101,  95, 118, 115,  95, 
     97, 100, 100,  95,  95, 104, 
    100, 114,  84, 101, 120, 116, 
    117, 114, 101,  48,  49,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0, 164,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  12,   0,   0,   0, 
    102, 108,  97, 115, 104, 101, 
    114,  77, 111, 100, 101,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 204,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  84, 101, 
    120, 116, 117, 114, 101,  48, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    244,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   9,   0, 
      0,   0,  84, 101, 120, 116, 
    117, 114, 101,  49,   0,   0, 
      0,   0,  12,   0,   0,   0, 
      4,   0,   0,   0,  68,   2, 
      0,   0,  84,   2,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 164,   0,   0,   0, 
      0,   1,   0,   0,  28,   2, 
      0,   0,  24,   2,   0,   0, 
     12,   0,   0,   0, 116, 101, 
    120,  83,  97, 109, 112, 108, 
    101, 114,  48,   0,   9,   0, 
      0,   0,  84,  69,  88,  85, 
     78,  73,  84,  48,   0,   0, 
      0,   0,  12,   0,   0,   0, 
      4,   0,   0,   0, 148,   3, 
      0,   0, 164,   3,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   6,   0,   0,   0, 
    164,   0,   0,   0,   0,   1, 
      0,   0, 124,   2,   0,   0, 
    120,   2,   0,   0, 171,   0, 
      0,   0,   0,   1,   0,   0, 
    148,   2,   0,   0, 144,   2, 
      0,   0, 169,   0,   0,   0, 
      0,   1,   0,   0, 180,   2, 
      0,   0, 176,   2,   0,   0, 
    170,   0,   0,   0,   0,   1, 
      0,   0, 212,   2,   0,   0, 
    208,   2,   0,   0, 165,   0, 
      0,   0,   0,   1,   0,   0, 
    244,   2,   0,   0, 240,   2, 
      0,   0, 166,   0,   0,   0, 
      0,   1,   0,   0,  20,   3, 
      0,   0,  16,   3,   0,   0, 
     12,   0,   0,   0, 116, 101, 
    120,  83,  97, 109, 112, 108, 
    101, 114,  49,   0,   9,   0, 
      0,   0,  84,  69,  88,  85, 
     78,  73,  84,  49,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     16,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     80,  48,   0,   0,  14,   0, 
      0,   0,  98,  97, 115, 105, 
     99,  95, 110, 111,  76, 105, 
    103, 104, 116,   0,   0,   0, 
      9,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 140,   0,   0,   0, 
    168,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    208,   0,   0,   0, 236,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  40,   1, 
      0,   0,  68,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 132,   1,   0,   0, 
    160,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   1,   0,   0, 200,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 220,   1, 
      0,   0, 240,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   2,   0,   0, 
     48,   2,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,  48,   3, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 236,   3, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 228,   3, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 146,   0, 
      0,   0,   0,   0,   0,   0, 
    184,   3,   0,   0, 180,   3, 
      0,   0, 147,   0,   0,   0, 
      0,   0,   0,   0, 208,   3, 
      0,   0, 204,   3,   0,   0, 
      2,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 168,  14,   0,   0, 
      0,   3, 255, 255, 254, 255, 
     95,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  71,   1, 
      0,   0,   0,   3, 255, 255, 
      5,   0,   0,   0,  28,   0, 
      0,   0,   0,   0,   0,  32, 
     64,   1,   0,   0, 128,   0, 
      0,   0,   2,   0,  16,   0, 
      1,   0,   0,   0, 168,   0, 
      0,   0, 184,   0,   0,   0, 
    200,   0,   0,   0,   2,   0, 
     17,   0,   1,   0,   0,   0, 
    168,   0,   0,   0, 184,   0, 
      0,   0, 244,   0,   0,   0, 
      2,   0,  15,   0,   1,   0, 
      0,   0, 168,   0,   0,   0, 
    184,   0,   0,   0,   6,   1, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  20,   1, 
      0,   0,   0,   0,   0,   0, 
     36,   1,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
     48,   1,   0,   0,   0,   0, 
      0,   0,  97, 108, 112, 104, 
     97,  84, 101, 115, 116,  86, 
     97, 108, 117, 101,  65,  66, 
     95, 102, 105, 108, 116, 101, 
    114,  77, 111, 100, 101,  95, 
     97, 100, 100,  66, 108, 101, 
    110, 100,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  97, 109, 111, 117, 
    110, 116,  95,  95,  98, 108, 
    101, 110, 100,  95, 109, 111, 
    100, 117, 108,  97, 116, 101, 
     95, 118, 115,  95,  97, 100, 
    100,  95,  95, 104, 100, 114, 
     84, 101, 120, 116, 117, 114, 
    101,  48,  49,   0, 115, 116, 
     97, 116, 105,  99,  67, 111, 
    108, 111, 114,  95,  65, 108, 
    112, 104,  97,   0, 116, 101, 
    120,  83,  97, 109, 112, 108, 
    101, 114,  48,   0, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 116, 101, 
    120,  83,  97, 109, 112, 108, 
    101, 114,  49,   0,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 112, 115,  95,  51, 
     95,  48,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0, 254, 255, 
    255,   1,  80,  82,  69,  83, 
      1,   2,  88,  70, 254, 255, 
     76,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 251,   0, 
      0,   0,   1,   2,  88,  70, 
      3,   0,   0,   0,  28,   0, 
      0,   0,   0,   1,   0,  32, 
    248,   0,   0,   0,  88,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0, 128,   0, 
      0,   0, 144,   0,   0,   0, 
    160,   0,   0,   0,   2,   0, 
      1,   0,   1,   0,   0,   0, 
    204,   0,   0,   0, 144,   0, 
      0,   0, 220,   0,   0,   0, 
      2,   0,   2,   0,   1,   0, 
      0,   0, 232,   0,   0,   0, 
    144,   0,   0,   0,  97, 108, 
    112, 104,  97,  84, 101, 115, 
    116,  86,  97, 108, 117, 101, 
     65,  66,  95, 102, 105, 108, 
    116, 101, 114,  77, 111, 100, 
    101,  95,  97, 100, 100,  66, 
    108, 101, 110, 100,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  97, 109, 
    111, 117, 110, 116,  95,  95, 
     98, 108, 101, 110, 100,  95, 
    109, 111, 100, 117, 108,  97, 
    116, 101,  95, 118, 115,  95, 
     97, 100, 100,  95,  95, 104, 
    100, 114,  84, 101, 120, 116, 
    117, 114, 101,  48,  49,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 102, 108, 
     97, 115, 104, 101, 114,  77, 
    111, 100, 101,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 116, 120,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
    254, 255,  16,   0,  80,  82, 
     83,  73,   5,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,  10,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0, 254, 255,  42,   0, 
     67,  76,  73,  84,  20,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0, 192,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    240,  63,   0,   0,   0,   0, 
      0,   0, 240, 191,   0,   0, 
      0,   0,   0,   0,   8, 192, 
      0,   0,   0,   0,   0,   0, 
     16, 192,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    254, 255, 114,   1,  70,  88, 
     76,  67,  36,   0,   0,   0, 
      1,   0,  64, 160,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,  16,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
     16, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  48, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
     16,  16,   1,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16, 160,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,  16,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
     64, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,  48,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  14,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,   0,  48, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  16,   1,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,  16, 160, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     20,   0,   0,   0,   1,   0, 
     16,  16,   1,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16, 160,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,  16,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,  48,   3,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  14,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  12,   0,   0,   0, 
      1,   0,  64, 160,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,  16,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
     16, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  48, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     16,   0,   0,   0,   1,   0, 
     64, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,  16, 160, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     40,   0,   0,   0,   1,   0, 
     64, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,  16, 160, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     44,   0,   0,   0,   1,   0, 
     64, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,  16, 160, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     48,   0,   0,   0,   1,   0, 
     16,  16,   1,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,  16, 160,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  52,   0, 
      0,   0,   1,   0,  48,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
     64, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  56,   0,   0,   0, 
    240, 240, 240, 240,  15,  15, 
     15,  15, 255, 255,   0,   0, 
     81,   0,   0,   5,  18,   0, 
     15, 160,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
    128, 191, 230, 174,  37,  61, 
     81,   0,   0,   5,  19,   0, 
     15, 160, 145, 131, 158,  61, 
    110, 167, 114,  63,  25, 137, 
     85,  61, 154, 153,  25,  64, 
     81,   0,   0,   5,  20,   0, 
     15, 160,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,   3, 144, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   1,   8,  15, 160, 
     40,   0,   0,   1,   0,   8, 
    228, 224,  66,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 144,   0,   8, 228, 160, 
      2,   0,   0,   3,   1,   0, 
      1, 128,   0,   0, 255, 129, 
     16,   0,   0, 160,  88,   0, 
      0,   4,   1,   0,   1, 128, 
      1,   0,   0, 128,  18,   0, 
      0, 160,  18,   0,  85, 160, 
     42,   0,   0,   0,   1,   0, 
      0,   2,   0,   0,  15, 128, 
     18,   0,  85, 160,   1,   0, 
      0,   2,   1,   0,   1, 128, 
     18,   0,  85, 160,  43,   0, 
      0,   0,  40,   0,   0,   1, 
      1,   8, 228, 224,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0, 228, 144,   1,   8, 
    228, 160,   2,   0,   0,   3, 
      1,   0,   2, 128,   2,   0, 
    255, 129,  16,   0,  85, 160, 
     88,   0,   0,   4,   1,   0, 
      2, 128,   1,   0,  85, 128, 
     18,   0,   0, 160,  18,   0, 
     85, 160,   2,   0,   0,   3, 
      1,   0,   2, 128,   1,   0, 
     85, 128,   1,   0,   0, 128, 
     88,   0,   0,   4,   1,   0, 
      1, 128,   1,   0,  85, 129, 
     18,   0,  85, 160,  18,   0, 
      0, 160,  42,   0,   0,   0, 
      1,   0,   0,   2,   2,   0, 
     15, 128,  18,   0,  85, 160, 
     43,   0,   0,   0,  88,   0, 
      0,   4,   1,   0,  15, 128, 
      1,   0,   0, 129,  18,   0, 
      0, 160,  18,   0, 170, 160, 
     65,   0,   0,   1,   1,   0, 
     15, 128,  40,   0,   0,   1, 
      2,   8, 228, 224,   2,   0, 
      0,   3,   1,   0,   7, 128, 
      0,   0, 228, 129,  18,   0, 
    255, 160,   5,   0,   0,   3, 
      3,   0,   3, 128,   0,   0, 
    228, 128,  19,   0,   0, 160, 
      4,   0,   0,   4,   3,   0, 
     12, 128,   0,   0,  68, 128, 
     19,   0,  85, 160,  19,   0, 
    170, 160,  32,   0,   0,   3, 
      1,   0,   8, 128,   3,   0, 
    170, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   0,   0, 
      1, 128,   1,   0,   0, 128, 
      3,   0,   0, 128,   1,   0, 
    255, 128,  32,   0,   0,   3, 
      1,   0,   1, 128,   3,   0, 
    255, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   0,   0, 
      2, 128,   1,   0,  85, 128, 
      3,   0,  85, 128,   1,   0, 
      0, 128,   5,   0,   0,   3, 
      1,   0,   1, 128,   0,   0, 
    170, 128,  19,   0,   0, 160, 
      4,   0,   0,   4,   1,   0, 
      2, 128,   0,   0, 170, 128, 
     19,   0,  85, 160,  19,   0, 
    170, 160,  32,   0,   0,   3, 
      3,   0,   1, 128,   1,   0, 
     85, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   0,   0, 
      4, 128,   1,   0, 170, 128, 
      1,   0,   0, 128,   3,   0, 
      0, 128,  43,   0,   0,   0, 
      5,   0,   0,   3,   1,   0, 
     15, 128,   0,   0, 228, 128, 
     15,   0, 228, 160,   1,   0, 
      0,   2,   3,   0,  15, 128, 
     15,   0, 228, 160,  88,   0, 
      0,   4,   1,   0,  15, 128, 
      5,   0,   0, 161,   1,   0, 
    228, 128,   3,   0, 228, 128, 
     40,   0,   0,   1,   1,   8, 
    228, 224,  40,   0,   0,   1, 
      3,   8, 228, 224,   2,   0, 
      0,   3,   3,   0,   7, 128, 
      2,   0, 228, 129,  18,   0, 
    255, 160,   5,   0,   0,   3, 
      4,   0,   3, 128,   2,   0, 
    228, 128,  19,   0,   0, 160, 
      4,   0,   0,   4,   4,   0, 
     12, 128,   2,   0,  68, 128, 
     19,   0,  85, 160,  19,   0, 
    170, 160,  32,   0,   0,   3, 
      3,   0,   8, 128,   4,   0, 
    170, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   2,   0, 
      1, 128,   3,   0,   0, 128, 
      4,   0,   0, 128,   3,   0, 
    255, 128,  32,   0,   0,   3, 
      3,   0,   1, 128,   4,   0, 
    255, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   2,   0, 
      2, 128,   3,   0,  85, 128, 
      4,   0,  85, 128,   3,   0, 
      0, 128,   5,   0,   0,   3, 
      3,   0,   1, 128,   2,   0, 
    170, 128,  19,   0,   0, 160, 
      4,   0,   0,   4,   3,   0, 
      2, 128,   2,   0, 170, 128, 
     19,   0,  85, 160,  19,   0, 
    170, 160,  32,   0,   0,   3, 
      4,   0,   1, 128,   3,   0, 
     85, 128,  19,   0, 255, 160, 
     88,   0,   0,   4,   2,   0, 
      4, 128,   3,   0, 170, 128, 
      3,   0,   0, 128,   4,   0, 
      0, 128,  43,   0,   0,   0, 
     40,   0,   0,   1,   4,   8, 
    228, 224,   2,   0,   0,   3, 
      3,   0,  15, 128,   0,   0, 
    228, 128,  20,   0,   0, 160, 
      5,   0,   0,   3,   4,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0, 228, 128,   2,   0, 
      0,   3,   4,   0,  15, 128, 
      4,   0, 228, 128,   4,   0, 
    228, 128,   2,   0,   0,   3, 
      5,   0,  15, 128,   0,   0, 
    228, 129,  18,   0,   0, 160, 
      2,   0,   0,   3,   5,   0, 
     15, 128,   5,   0, 228, 128, 
      5,   0, 228, 128,   2,   0, 
      0,   3,   6,   0,  15, 128, 
      2,   0, 228, 129,  18,   0, 
      0, 160,   4,   0,   0,   4, 
      5,   0,  15, 128,   5,   0, 
    228, 128,   6,   0, 228, 129, 
     18,   0,   0, 160,  88,   0, 
      0,   4,   3,   0,  15, 128, 
      3,   0, 228, 128,   5,   0, 
    228, 128,   4,   0, 228, 128, 
     11,   0,   0,   3,   4,   0, 
     15, 128,   3,   0, 228, 128, 
     18,   0,  85, 160,   5,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   4,   0, 
    228, 128,  43,   0,   0,   0, 
      5,   0,   0,   3,   3,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   3,   0,  15, 128, 
      3,   0, 228, 128,  17,   0, 
      0, 160,   5,   0,   0,   3, 
      3,   0,  15, 128,   1,   0, 
    228, 128,   3,   0, 228, 128, 
     88,   0,   0,   4,   3,   0, 
     15, 128,  10,   0,   0, 161, 
      3,   0, 228, 128,   1,   0, 
    228, 128,   4,   0,   0,   4, 
      4,   0,  15, 128,   2,   0, 
    228, 128,  17,   0,   0, 160, 
      0,   0, 228, 128,   5,   0, 
      0,   3,   4,   0,  15, 128, 
      3,   0, 228, 128,   4,   0, 
    228, 128,  88,   0,   0,   4, 
      3,   0,  15, 128,  11,   0, 
      0, 161,   4,   0, 228, 128, 
      3,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 129,  18,   0, 
      0, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 129,  18,   0,   0, 160, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0, 228, 129,  18,   0, 
      0, 160,  11,   0,   0,   3, 
      2,   0,  15, 128,   0,   0, 
    228, 128,  18,   0,  85, 160, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   2,   0, 228, 128, 
      3,   0, 228, 128,  88,   0, 
      0,   4,   1,   0,  15, 128, 
     12,   0,   0, 161,   0,   0, 
    228, 128,   3,   0, 228, 128, 
     43,   0,   0,   0,   5,   0, 
      0,   3,   0,   0,   1, 128, 
      1,   0, 255, 128,  17,   0, 
     85, 161,   5,   0,   0,   3, 
      0,   0,   7, 128,   0,   0, 
      0, 128,   1,   0, 228, 128, 
     88,   0,   0,   4,   0,   8, 
      7, 128,  13,   0,   0, 161, 
      1,   0, 228, 128,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   0,   1, 128,  13,   0, 
      0, 160,  88,   0,   0,   4, 
      0,   8,   8, 128,   0,   0, 
      0, 129,   1,   0, 255, 128, 
     14,   0,   0, 160, 255, 255, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      0,   0,   0,   0,  88,   1, 
      0,   0,   0,   3, 254, 255, 
    254, 255,  52,   0,  67,  84, 
     65,  66,  28,   0,   0,   0, 
    155,   0,   0,   0,   0,   3, 
    254, 255,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   0, 
      0,  32, 148,   0,   0,   0, 
     48,   0,   0,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
     68,   0,   0,   0,  84,   0, 
      0,   0, 109,  97, 116,  87, 
    111, 114, 108, 100,  86, 105, 
    101, 119,  80, 114, 111, 106, 
      0, 171, 171, 171,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 115,  95,  51,  95,  48, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   0, 128,   1,   0, 
     15, 144,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 224,  31,   0,   0,   2, 
      5,   0,   0, 128,   1,   0, 
      3, 224,   9,   0,   0,   3, 
      0,   0,   1, 224,   0,   0, 
    228, 144,   0,   0, 228, 160, 
      9,   0,   0,   3,   0,   0, 
      2, 224,   0,   0, 228, 144, 
      1,   0, 228, 160,   9,   0, 
      0,   3,   0,   0,   4, 224, 
      0,   0, 228, 144,   2,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   8, 224,   0,   0, 
    228, 144,   3,   0, 228, 160, 
      1,   0,   0,   2,   1,   0, 
      3, 224,   1,   0, 228, 144, 
    255, 255,   0,   0, 255, 255, 
    255, 255,   8,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  84, 101, 
    120, 116, 117, 114, 101,  49, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  84, 101, 
    120, 116, 117, 114, 101,  48, 
      0,   0,   0,   0
};