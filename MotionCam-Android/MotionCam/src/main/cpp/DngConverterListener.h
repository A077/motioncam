#ifndef MOTIONCAM_ANDROID_DNGCONVERTERLISTENER_H
#define MOTIONCAM_ANDROID_DNGCONVERTERLISTENER_H

#include <motioncam/DngProcessorProgress.h>
#include <jni.h>
#include <string>

class DngConverterListener : public motioncam::DngProcessorProgress {
public:
    DngConverterListener(_JNIEnv* env, _jobject* progressListener);
    ~DngConverterListener();

    int onNeedFd(int frameNumber) const;
    bool onProgressUpdate(int progress) const;
    void onCompleted(int fd) const;
    void onCompleted() const;
    void onError(const std::string& error) const;

private:
    _JNIEnv * mEnv;
    _jobject *mProgressListenerRef;
};


#endif //MOTIONCAM_ANDROID_DNGCONVERTERLISTENER_H
