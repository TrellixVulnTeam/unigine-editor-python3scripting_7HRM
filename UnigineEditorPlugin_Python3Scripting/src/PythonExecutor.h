#pragma once

#include <vector>
#include <QVector>
#include <UnigineMaterials.h>
#include "unigine_python_wrapper_base.h"

class PythonExecutor {
    public:
        PythonExecutor(
            const std::string &sExtensionId,
            const std::string &sDirPathWithModules
        );
        ~PythonExecutor();
        void addMaterials(const QVector<Unigine::UGUID> &vGuids);
        void addProperties(const QVector<Unigine::UGUID> &vGuids);
        void addRuntimes(const QVector<Unigine::UGUID> &vGuids);
        void addNodes(const QVector<Unigine::NodePtr> &vNodes);

        int execCode(const std::string &sScriptContent);
        int execFile(const std::string &sScriptPath);
    private:
        std::vector<UniginePythonWrapperBase *> m_vWrappers;
        std::string m_sExtensionId;
        std::string m_sDirPathWithModules;
        void* m_pGlobalDict;
};