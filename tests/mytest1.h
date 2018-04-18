#ifndef MYTETS1_H
#define MYTETS1_H

#include <gtest/gtest.h>
#include <fcntl.h>
#include <stdio.h>

extern "C" {
#include "text.h"
#include "_text.h"
#include "common.h"
}

#define OUTPUT 1

TEST(start, start_function)
{
    text txt = create_text();
    shownumspaces(txt);
    SUCCEED();
}

TEST(shownumspases_test, EmptyLine)
{
    int outFd = open("OutputFile_Test_EmptyLine", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    int oldOutput = dup(2);
    dup2(outFd, 2);

    char* filename = (char*)malloc(1024 * sizeof(char));
    sprintf(filename, "%s/input/InputFile_EmptyLine", INPUTDIR);

    text txt = create_text();
    load(txt, filename);
    shownumspaces(txt);

    close(outFd);
    dup2(oldOutput, 2);
    int testFd = open("OutputFile_Test_EmptyLine",  O_RDONLY);
    sprintf(filename, "%s/output/OutputFile_Original_EmptyLine", INPUTDIR);
    int originFd = open(filename, O_RDONLY);
    int outputCount;
    int originCount;
    int BufferSize = 44;
    char* TestOutBuffer = (char*)malloc(1024 * sizeof(char));
    char* OriginOutBuffer = (char*)malloc(1024 * sizeof(char));

    do {
        outputCount = read(testFd, (void*)TestOutBuffer, BufferSize);
        originCount = read(originFd, (void*)OriginOutBuffer, BufferSize);
        ASSERT_EQ(outputCount, originCount);
        for (int i = 0; i < outputCount; i++)
        {
            ASSERT_EQ(TestOutBuffer[i], OriginOutBuffer[i]);
        }
    } while (outputCount > 0);

    free(filename);
    free(TestOutBuffer);
    free(OriginOutBuffer);
}

TEST(shownumspaces_test, OnlySpaces)
{
    int outFd = open("OutputFile_Test_OnlySpaces", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    int oldOutput = dup(1);
    dup2(outFd, 1);

    char* filename = (char*)malloc(1024 * sizeof(char));
    sprintf(filename, "%s/input/InputFile_OnlySpaces", INPUTDIR);

    text txt = create_text();
    load(txt, filename);
    shownumspaces(txt);

    close(outFd);
    fflush(stdout);
    dup2(oldOutput, 1);

    int testFd = open("OutputFile_Test_OnlySpaces",  O_RDONLY);
    sprintf(filename, "%s/output/OutputFile_Original_OnlySpaces", INPUTDIR);
    int originFd = open(filename, O_RDONLY);
    int outputCount;
    int originCount;
    int BufferSize = 10;
    char* TestOutBuffer = (char*)malloc(1024 * sizeof(char));
    char* OriginOutBuffer = (char*)malloc(1024 * sizeof(char));

    do {
        outputCount = read(testFd, (void*)TestOutBuffer, BufferSize);
        originCount = read(originFd, (void*)OriginOutBuffer, BufferSize);
        ASSERT_EQ(outputCount, originCount);
        for (int i = 0; i < outputCount; i++)
        {
            ASSERT_EQ(TestOutBuffer[i], OriginOutBuffer[i]);
        }
    } while (outputCount > 0);

    free(filename);
    free(TestOutBuffer);
    free(OriginOutBuffer);
}

TEST(shownumspaces_test, NormalInput)
{
    int outFd = open("OutputFile_Test_NormalInput", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    int oldOutput = dup(1);
    dup2(outFd, 1);

    char* filename = (char*)malloc(1024 * sizeof(char));
    sprintf(filename, "%s/input/InputFile_NormalInput", INPUTDIR);

    text txt = create_text();
    load(txt, filename);
    shownumspaces(txt);

    close(outFd);
    fflush(stdout);
    dup2(oldOutput, 1);

    int testFd = open("OutputFile_Test_NormalInput",  O_RDONLY);
    sprintf(filename, "%s/output/OutputFile_Original_NormalInput", INPUTDIR);
    int originFd = open(filename, O_RDONLY);
    int outputCount;
    int originCount;
    int BufferSize = 28;
    char* TestOutBuffer = (char*)malloc(1024 * sizeof(char));
    char* OriginOutBuffer = (char*)malloc(1024 * sizeof(char));

    do {
        outputCount = read(testFd, (void*)TestOutBuffer, BufferSize);
        originCount = read(originFd, (void*)OriginOutBuffer, BufferSize);
        ASSERT_EQ(outputCount, originCount);
        for (int i = 0; i < outputCount; i++)
        {
            ASSERT_EQ(TestOutBuffer[i], OriginOutBuffer[i]);
        }
    } while (outputCount > 0);

    free(filename);
    free(TestOutBuffer);
    free(OriginOutBuffer);
}
#endif // MYTETS1_H
