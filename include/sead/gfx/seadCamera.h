/**
 * @file camera.h
 * @brief Basic camera implementation.
 */

#pragma once

#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>
#include <sead/prim/seadRuntimeTypeInfo.h>

namespace sead
{
    class OrthoProjection;

    class Camera
    {
        
        SEAD_RTTI_BASE(Camera)

    public:
        Camera() = default;
        virtual ~Camera();

        virtual void doUpdateMatrix(Matrix34f *) const = 0;

        void getWorldPosByMatrix(Vector3f *) const;
        void getLookVectorByMatrix(Vector3f *) const;
        void getRightVectorByMatrix(Vector3f *) const;
        void getUpVectorByMatrix(Vector3f *) const;
        void worldPosToCameraPosByMatrix(Vector3f *, Vector3f const &) const;
        void cameraPosToWorldPosByMatrix(Vector3f *, Vector3f const &) const;

        Matrix34f camMatrix;   // 30
    };

    class LookAtCamera : public Camera
    {

        SEAD_RTTI_OVERRIDE(LookAtCamera, Camera)

    public:
        LookAtCamera(Vector3f const &pos, Vector3f const &at, Vector3f const &up);

        Vector3f& getPos() { return mPos; }
        Vector3f& getAt() { return mAt; }
        Vector3f& getUp() { return mUp; }
        const Vector3f& getPos() const { return mPos; }
        const Vector3f& getAt() const { return mAt; }
        const Vector3f& getUp() const { return mUp; }

        void doUpdateMatrix(Matrix34f *) const override;
    //private:
        Vector3f mPos;
        Vector3f mAt;
        Vector3f mUp;
    };

    class DirectCamera : public Camera
    {
    public:
        virtual ~DirectCamera();

        virtual void doUpdateMatrix(Matrix34f *);
    };

    class OrthoCamera : public LookAtCamera
    {
    public:
        OrthoCamera();
        OrthoCamera(Vector2f const &, f32);
        OrthoCamera(OrthoProjection const &);

        virtual ~OrthoCamera();

        virtual bool checkDerivedRuntimeTypeInfo(RuntimeTypeInfo::Interface const *);
        virtual RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;

        void setByOrthoProjection(OrthoProjection const &);
        void setRotation(f32 rotation);
    };
};